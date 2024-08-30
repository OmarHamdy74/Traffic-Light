/*
 * button.h
 *
 * Created: 09/12/2022 09:02:22 م
 *  Author: omarh
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_



#define LOW 0
#define HIGH 1



#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/TIMER DRIVER/timer.h"


/*						All Driver Function Prototypes                  */

/* Name	: Button Initialization 
 * Function : it takes 2 inputs and return void (error handling)
 */
void BUTTON_initial(uint8_t button_Port , uint8_t button_Pin);


/* Name	: Button Read
 * Function : it takes 3 inputs and return void (error handling)
 */ 
void BUTTON_read(uint8_t button_Port , uint8_t button_Pin , uint8_t *value);





#endif /* BUTTON_H_ */