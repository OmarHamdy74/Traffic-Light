/*
 * dio.c
 *
 * Created: 09/12/2022 09:03:02 م
 *  Author: omarh
 */ 


#include "dio.h"

/*			Function Definitions                            */


/* Name	: DIO Initialization 
 * Function : it takes 3 inputs and return void (error handling)
 */
void DIO_initial(uint8_t port_Number , uint8_t pin_Number , uint8_t direction)
{
	switch(port_Number)
	{
		case PORT_A :
		if(direction == IN)
		{
			DDRA &= ~(1<<pin_Number);
		}
		else if(direction == OUT)
		{
			DDRA |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
		
		case PORT_B:
		if(direction == IN)
		{
			DDRB &= ~(1<<pin_Number);
		}
		else if(direction == OUT)
		{
			DDRB |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		break;
		
		case PORT_C:
		if(direction == IN)
		{
			DDRC &= ~(1<<pin_Number);
		}
		else if(direction == OUT)
		{
			DDRC |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
		
		case PORT_D :
		if(direction == IN)
		{
			DDRD &= ~(1<<pin_Number);
		}
		else if(direction == OUT)
		{
			DDRD |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
	}
	
}


/* Name	: DIO Write
 * Function : it takes 3 inputs and return void (error handling) (write on the dio pins)
 */
void DIO_write(uint8_t port_Number , uint8_t pin_Number , uint8_t value)
{
	switch(port_Number)
	{
		case PORT_A:
		if(value == LOW)
		{
			PORTA &= ~(1<<pin_Number);
		}
		else if(value == HIGH)
		{
			PORTA |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &= ~(1<<pin_Number);
		}
		else if(value == HIGH)
		{
			PORTB |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			PORTC &= ~(1<<pin_Number);
		}
		else if(value == HIGH)
		{
			PORTC |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
		
		case PORT_D:
		if(value == LOW)
		{
			PORTD &= ~(1<<pin_Number);
		}
		else if(value == HIGH)
		{
			PORTD |= (1<<pin_Number);
		}
		else
		{
			// return error
		}
		
		break;
	}
	
}


/* Name	: DIO Toggle 
 * Function : it takes 2 inputs and return void (error handling) (toggle the dio pins)
 */
void DIO_toggle(uint8_t  port_Number , uint8_t  pin_Number)
{
	// Check For Valid Inputs

	switch (port_Number)
	{
		case PORT_A : PORTA ^=(1<<pin_Number);
		break;
		case PORT_B : PORTB ^=(1<<pin_Number);
		break;
		case PORT_C : PORTC ^=(1<<pin_Number);
		break;
		case PORT_D : PORTD ^=(1<<pin_Number);
		break;
	}


}


/* Name	: DIO Read
 * Function : it takes 3 inputs and return void (error handling) (read the value of dio pins)
 */
void DIO_read(uint8_t port_Number , uint8_t pin_Number , uint8_t *value)
{
	switch(port_Number)
	{
		case PORT_A:
		*value = (PINA & (1<<pin_Number))>>pin_Number;
		break;
		case PORT_B:
		*value = (PINB & (1<<pin_Number))>>pin_Number;
		break;
		case PORT_C:
		*value = (PINC & (1<<pin_Number))>>pin_Number;
		break;
		case PORT_D:
		*value = (PIND & (1<<pin_Number))>>pin_Number;
		break;
		default:
		//return error
		break;
		
	}
}