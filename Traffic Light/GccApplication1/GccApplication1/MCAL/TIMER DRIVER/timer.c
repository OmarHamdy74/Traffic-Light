/*
 * timer.c
 *
 * Created: 09/12/2022 09:03:24 م
 *  Author: omarh
 */ 

#include "timer.h"

/*			TIMER0 Function Definitions                     */

/* Name	: TIMER 0 Initialization 
 * Function : it takes 1 input and return void (error handling)
 */
void TIMER0_initial(uint8_t timer_Mode)
{
	// Check For Valid Inputs
	if(timer_Mode <= Fast_PWM_Mode)
	{
		switch(timer_Mode)
		{
			case Normal_Mode:
				TCCR0 = 0x00;
				 break;
			case Phase_Correct_Mode:
				TCCR0 = 0x40;
				 break;
			case CTC_Mode:
				TCCR0 = 0x08;
				 break;
			case Fast_PWM_Mode:
				TCCR0 = 0x48;
				  break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Name	: TIMER 0 Start 
 * Function : it takes 2 inputs and return void (error handling)
 */
void TIMER0_start(uint8_t timer_Prescaller, uint8_t initial_Value)
{
	TCNT0 = initial_Value;
	
	// Check For Valid Inputs
	if(timer_Prescaller <= Prescaller_1024)
	{
		switch(timer_Prescaller)
		{
			case NO_Prescaller:
			
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break;
			
			case Prescaller_8:
			
			TCCR0 &= ~(1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break;
			
			case Prescaller_64:
			
			TCCR0 |= (1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			break;
			
			case Prescaller_256:
			
			TCCR0 &= ~(1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			break;
			
			case Prescaller_1024:
			
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			break;
		}
	}
}



/* Name	: TIMER 0 Stop
 * Function : no inputs and return void (error handling)
 */
void TIMER0_stop(void)
{
	TCCR0 = 0x00;
}


/* Name	: TIMER 0 Delay 
 * Function : it takes 3 inputs and return void (error handling)
 */
void TIMER0_delay(uint8_t timer_Prescaller, uint8_t initial_Value, uint32_t Number_Of_OverFlows)
{
	// Reset The Over Flow Counter
	uint32_t overFlowCounter   = 0;
	
	// Start TIMER 0
	TIMER0_start(timer_Prescaller, initial_Value);
	
	while( overFlowCounter < Number_Of_OverFlows) 
	{
		
		/* FCPU = 1 000 000  
		 * Overflow -> 16 384 microsecond ( PRESCALER_64 )  
		 */
		
		
		/* T(tick) = 1 / F(clock) = Prescaller / F(cpu) = 64 / 1 000 000 = 64 microseconds
		 * T(max_delay) = T(tick) * 2^(n) = 64 microseconds * 2(8) = 16.384 ms
		 * 1 sec = 1 000 ms 
		 * Number_Of_OverFlows = (ceil) T(delay) / T(max_delay) = (ceil) 1 000 ms / 16.384 ms = 61
		 * Timer(initial_value) = (T(max_delay) - T(delay)) / T(tic) = (16.384 ms - 1) / 64 microseconds = -15369
		 * add 256 to -15369 until it equal a positive number 
		 * Timer(initial_value) = 247 
		 */
		
	
		 
		
		// wait until the overflow flag to be set
		while(((TIFR>>TOV0) & 1) == 0); 
		
		// Clear the overflow flag
		TIFR &= ~(1<<TOV0);
		
		overFlowCounter++;
		
	}
	
	overFlowCounter = 0;
	
	TIMER0_stop();
}



/*			TIMER2 Function Definitions                     */

/* Name	: TIMER 2 Initialization 
 * Function : it takes 1 inputs and return void (error handling)
 */
void TIMER2_initial(uint8_t timer_Mode)
{
	// Check For Valid Inputs
	if(timer_Mode <= Fast_PWM_Mode)
	{
		switch(timer_Mode)
		{
			case Normal_Mode:			TCCR2 = 0x00; break;
			case Phase_Correct_Mode:	TCCR2 = 0x40; break;
			case CTC_Mode:				TCCR2 = 0x08; break;
			case Fast_PWM_Mode:			TCCR2 = 0x48; break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Name	: TIMER 2 Start 
 * Function : it takes 2 inputs and return void (error handling)
 */
void TIMER2_start(uint8_t timer_Prescaller, uint8_t initial_Value)
{
	TCNT2 = initial_Value;
	
	// Check For Valid Inputs
	if(timer_Prescaller <= Prescaller_1024)
	{
		switch(timer_Prescaller)
		{
			case NO_Prescaller:
			
			TCCR2 |= (1<<CS20);
			TCCR2 &= ~(1<<CS21);
			TCCR2 &= ~(1<<CS22);
			break;
			
			case Prescaller_8:
			
			TCCR2 &= ~(1<<CS20);
			TCCR2 |= (1<<CS21);
			TCCR2 &= ~(1<<CS22);
			break;
			
			case Prescaller_64:
			
			TCCR2 |= (1<<CS20);
			TCCR2 |= (1<<CS21);
			TCCR2 &= ~(1<<CS22);
			break;
			
			case Prescaller_256:
			
			TCCR2 &= ~(1<<CS20);
			TCCR2 &= ~(1<<CS21);
			TCCR2 |= (1<<CS22);
			break;
			
			case Prescaller_1024:
			
			TCCR2 |= (1<<CS20);
			TCCR2 &= ~(1<<CS21);
			TCCR2 |= (1<<CS22);
			break;
		}
	}
}


/* Name	: TIMER 2 Stop 
 * Function : it takes no inputs and return void (error handling)
 */
void TIMER2_stop(void)
{
	TCCR2 = 0x00;
}







