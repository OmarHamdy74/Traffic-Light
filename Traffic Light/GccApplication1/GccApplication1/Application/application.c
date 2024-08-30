/*
 * application.c
 *
 * Created: 09/12/2022 09:03:57 م
 *  Author: omarh
 */ 

#define F_CPU 1000000UL

#include "../ECUAL/LED DRIVER/led.h"
#include "../ECUAL/BUTTON DRIVER/button.h"
#include "../Utilities/interrupts.h"
#include "application.h"


uint8_t Yellow_Button       = 0;

// My Counters
uint8_t Seconds_Count		= 0;
uint32_t Overflow_Count 	= 0;
uint32_t Overflow_Count2    = 0;

// My Flags
uint8_t Car_State	 	    = 0;
uint8_t Yellow_Flag	     	= 0;
uint8_t Pressed_Button_Flag	= 0;



/*				INITIALIZATION				*/
void Application_initial()
{
	/* DIO Initialization */
	
	// Set Output for LEDs Directions
	DIO_initial(Car_Port , Car_Green_Pin , OUT);
	DIO_initial(Car_Port , Car_Yellow_Pin , OUT);
	DIO_initial(Car_Port , Car_Red_Pin , OUT);
	
	DIO_initial(Pedestrian_Port , Pedestrian_Green_Pin , OUT);
	DIO_initial(Pedestrian_Port , Pedestrian_Yellow_Pin , OUT);
	DIO_initial(Pedestrian_Port , Pedestrian_Red_Pin , OUT);
	
	// Set Input for Button Directions
	BUTTON_initial(Button_Port, Button_Pin);
	
	
	/* Interrupts Initialization */
	
	// Enable The Global Interrupt
	SREG |= (1<<GIE);
	
	
	// INT 0 Detect Any Logical Change ( to distinguish between a short and a long press on the button)
	MCUCR |= (1<<ISC00);
	MCUCR &= ~(1<<ISC01);
	
	// Enable INT0
	GICR |= (1<<INT0);

	
	// Enable The Overflow Interrupts for TIMER0 and TIMER2
	TIMSK |= (1<<TOIE0);
	TIMSK |= (1<<TOIE2);

	
	// Timer0 initialization
	TIMER0_initial(Normal_Mode);
	
	// Timer2 initialization
	TIMER2_initial(Normal_Mode);
	
	// Timer0 Start
	TIMER0_start(Prescaller_64 , Timer0_initial_Value);
}


/*				 APPLICATION		    	*/
void Application_Start()
{
	while (1)
	{
		// To Choose GREEN - YELLOW - RED - YELLOW - GREEN... And so on
		if (Car_State > Car_Yellow_2)
		{
			Car_State = Car_Green;
		}
		
		else
		{
			switch(Car_State)
			{
				case Car_Green:
				
				// Turn On The Car Green led and Pedestrian Red led
				LED_on(Car_Port , Car_Green_Pin);
				LED_off(Car_Port , Car_Yellow_Pin);
				LED_off(Car_Port , Car_Red_Pin);
				
				LED_off(Pedestrian_Port , Pedestrian_Green_Pin);
				LED_off(Pedestrian_Port , Pedestrian_Yellow_Pin);
				LED_on(Pedestrian_Port , Pedestrian_Red_Pin);
				
				Yellow_Flag = 0;
				break;
				
				case Car_Yellow_1:
				
				// We set the yellow flag to be able to blink
				Yellow_Flag = 1;
				
				LED_off(Car_Port , Car_Green_Pin);
				LED_off(Car_Port , Car_Red_Pin);
				
				LED_off(Pedestrian_Port , Pedestrian_Green_Pin );
				LED_off(Pedestrian_Port , Pedestrian_Red_Pin );
				break;
				
				case Car_Red:
				
				// Turn On Car RED led and Pedestrian GREEN led
				LED_off(Car_Port , Car_Green_Pin);
				LED_off(Car_Port , Car_Yellow_Pin);
				LED_on(Car_Port , Car_Red_Pin);
				
				LED_on(Pedestrian_Port , Pedestrian_Green_Pin );
				LED_off(Pedestrian_Port , Pedestrian_Yellow_Pin );
				LED_off(Pedestrian_Port , Pedestrian_Red_Pin );
				
				Yellow_Flag = 0;
				break;
				
				case Car_Yellow_2:
				
				// We set the yellow flag to be able to blink
				Yellow_Flag = 1;
				
				LED_off(Car_Port , Car_Green_Pin);
				LED_off(Car_Port , Car_Red_Pin);
				
				LED_off(Pedestrian_Port , Pedestrian_Green_Pin);
				LED_off(Pedestrian_Port , Pedestrian_Red_Pin);
				break;
				
				default:
				// do nothing
				break;
			}
		}
	}
}


//TIMER0 Overflow ISR 
ISR(TIMER0_OVF)
{
				if (Yellow_Button == 1)
				{
					Yellow_Button = 0;
					Seconds_Count = 0;
					Overflow_Count = 0;
				}
	
	// Check if it reached to the number of overflows to ( 1s )
	else if (Overflow_Count < Timer0_NumOfOverFlows)
	{
		Overflow_Count++;
	}
	
	else if (Overflow_Count >= Timer0_NumOfOverFlows)
	{
		// Increment a second
		Seconds_Count++;		
		
		if (Yellow_Flag == 1)
		// If the yellow flag is set, we switch all leds to yellow
		{	
			LED_toggle(Car_Port , Car_Yellow_Pin);
			LED_toggle(Pedestrian_Port , Pedestrian_Yellow_Pin);
		}		
		
		if (Seconds_Count == 5)
		{
			// When it reaches 5 seconds, go to the next state
			Car_State++;
			
			// Reset The Seconds Counter
			Seconds_Count = 0;
		}
		
		// Reset The Overflow Counter
		Overflow_Count = 0;
	}
}


//TIMER2 Overflow ISR 
ISR(TIMER_2_OVF)
{
	// Increment to The Overflow Counter
	Overflow_Count2++;
}


//EXT INT0 ISR 
ISR (EXT_INT_0)
{
	// Increment to The Pressed Flag
	Pressed_Button_Flag++;
	
	/* The Interrupt Is Set To Any Logical Change So That
	 * ( Rising Edge When Pressed and Falling When Released )
	 */
	
	switch(Pressed_Button_Flag)
	{
		case Pressed:
			
			TIMER2_start(Prescaller_64 , 47);
			break;
			
		case Released:
		
			// Check if Overflow_Count2 has become more than half a second or not
			if (Overflow_Count2 > Timer2_NumOfOverFlows)
			{
				// ( Long Press )
				// Do Nothing
			}
			
			// ( Short Press )
			else
			{
				if (Car_State == Car_Green)
				{
					// If The Car Signal is Green Switch it to Yellow
					Car_State++;
					
					// Reset The Counters
					Seconds_Count = 0;
					Overflow_Count = 0;
				}
				else if (Car_State == Car_Yellow_1)
				{
					Yellow_Button = 1;				
										
				}
				else if (Car_State == Car_Yellow_2)
				{
					Yellow_Button = 1;
					
				}				
				
		}
		
		// Stop TIMER2
		TIMER2_stop();
		
		// Reset The Counter and The Flag
		Overflow_Count2	= 0;
		Pressed_Button_Flag = 0;
		break;
	}
	
}





