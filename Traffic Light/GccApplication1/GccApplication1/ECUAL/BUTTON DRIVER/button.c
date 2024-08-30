/*
 * button.c
 *
 * Created: 09/12/2022 09:02:07 م
 *  Author: omarh
 */ 

#include "button.h"

/*			Function Definitions                            */


/* Name	: Button Initialization 
 * Function : it takes 2 inputs and return void (error handling)
 */ 
void BUTTON_initial(uint8_t button_Port , uint8_t button_Pin)
{
	DIO_initial(button_Port , button_Pin , IN);
}


/* Name	: Button Read
 * Function : it takes 3 inputs and return void (error handling)
 */ 
void BUTTON_read(uint8_t button_Port , uint8_t button_Pin , uint8_t *value)
{
	DIO_read(button_Port , button_Pin , value );
}