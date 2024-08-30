/*
 * led.h
 *
 * Created: 09/12/2022 09:02:48 م
 *  Author: omarh
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/TIMER DRIVER/timer.h"

/*						All Driver Function Prototypes                  */


/* Name	: LED Initialization 
 * Function : it takes 2 inputs and return void (error handling)
 */
void LED_initial(uint8_t led_Port , uint8_t led_Pin);


/* Name	: LED Turn On 
 * Function : it takes 2 inputs and return void (error handling) -- make the led on
 */
void LED_on(uint8_t led_Port , uint8_t led_Pin);


/* Name	: LED Turn Off 
 * Function : it takes 2 inputs and return void (error handling) -- make the led off
 */
void LED_off(uint8_t led_Port , uint8_t led_Pin);


/* Name	: LED Toggle 
 * Function : it takes 2 inputs and return void (error handling) -- make the led blink
 */
void LED_toggle(uint8_t led_Port , uint8_t led_Pin);



#endif /* LED_H_ */