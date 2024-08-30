/*
 * led.c
 *
 * Created: 09/12/2022 09:02:34 م
 *  Author: omarh
 */ 


#include "led.h"


/*			Function Definitions                            */


/* Name	: LED Initialization 
 * Function : it takes 2 inputs and return void (error handling)
 */
void LED_initial(uint8_t led_Port , uint8_t led_Pin)
{
	DIO_initial(led_Port , led_Pin ,OUT);
}


/* Name	: LED Turn On 
 * Function : it takes 2 inputs and return void (error handling) -- make the led on
 */
void LED_on(uint8_t led_Port , uint8_t led_Pin)
{
	DIO_write(led_Port , led_Pin , HIGH);
}


/* Name	: LED Turn Off 
 * Function : it takes 2 inputs and return void (error handling) -- make the led off
 */
void LED_off(uint8_t led_Port , uint8_t led_Pin)
{
	DIO_write(led_Port , led_Pin , LOW);
}


/* Name	: LED Toggle 
 * Function : it takes 2 inputs and return void (error handling) -- make the led blink
 */
void LED_toggle(uint8_t led_Port , uint8_t led_Pin)
{
	DIO_toggle(led_Port ,led_Pin);
}