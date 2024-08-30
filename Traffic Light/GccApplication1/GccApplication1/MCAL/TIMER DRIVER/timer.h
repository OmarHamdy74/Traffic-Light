/*
 * timer.h
 *
 * Created: 09/12/2022 09:03:36 م
 *  Author: omarh
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

// TIMER Mode Macros
#define Normal_Mode			0
#define Phase_Correct_Mode  1
#define CTC_Mode			2
#define Fast_PWM_Mode		3

// Prescaller Macros
#define NO_Prescaller	0
#define Prescaller_8	1
#define Prescaller_64	2
#define Prescaller_256	3
#define Prescaller_1024	4

//TIMSK
#define TOIE0	0
#define OCIE0	1
#define TOIE2	6
#define OCIE2	7

// TCCR0
#define CS00 0
#define CS01 1
#define CS02 2

// TCCR2
#define CS20 0
#define CS21 1
#define CS22 2

// TIFR
#define TOV0 0
#define TOV2 6


/*						All Timers Function Prototypes                  */

/* Name	: TIMER 0 Initialization 
 * Function : it takes 1 input and return void (error handling)
 */
void TIMER0_initial(uint8_t timer_Mode);


/* Name	: TIMER 0 Start 
 * Function : it takes 2 inputs and return void (error handling)
 */
void TIMER0_start(uint8_t timer_Prescaller, uint8_t initial_Value);



/* Name	: TIMER 0 Stop
 * Function : no inputs and return void (error handling)
 */
void TIMER0_stop(void);



/* Name	: TIMER 0 Delay 
 * Function : it takes 3 inputs and return void (error handling)
 */
void TIMER0_delay(uint8_t timer_Prescaller, uint8_t initial_Value, uint32_t Number_Of_OverFlows);		


/* Name	: TIMER 2 Initialization 
 * Function : it takes 1 inputs and return void (error handling)
 */
void TIMER2_initial(uint8_t timer_Mode);


/* Name	: TIMER 2 Start 
 * Function : it takes 2 inputs and return void (error handling)
 */
void TIMER2_start(uint8_t timer_Prescaller, uint8_t initial_Value);

/* Name	: TIMER 2 Stop 
 * Function : it takes no inputs and return void (error handling)
 */
void TIMER2_stop(void);






#endif /* TIMER_H_ */