/*
 * application.h
 *
 * Created: 09/12/2022 09:04:09 م
 *  Author: omarh
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

// PORT 
#define Car_Port				PORT_A
#define Pedestrian_Port 	    PORT_B
#define Button_Port				PORT_D

// PIN 
#define Car_Green_Pin       0
#define Car_Yellow_Pin      1
#define Car_Red_Pin         2

#define Pedestrian_Green_Pin       0
#define Pedestrian_Yellow_Pin      1
#define Pedestrian_Red_Pin         2

#define Button_Pin          2

// Car Signal State 
#define Car_Green				0
#define Car_Yellow_1			1
#define Car_Red					2
#define Car_Yellow_2			3

// Timer 
#define Timer0_initial_Value	247
#define Timer0_NumOfOverFlows	62

#define TIMER2_initial_Value	47
#define Timer2_NumOfOverFlows	30

// Button 
#define Pressed		1
#define Released	2


/* Name	: APP Initialization 
 * Function : its input is void and return void
 */
void Application_initial(void);


/* Name	: App Implementation
 * Function : its input is void and return void
 */
void Application_Start(void);




#endif /* APPLICATION_H_ */