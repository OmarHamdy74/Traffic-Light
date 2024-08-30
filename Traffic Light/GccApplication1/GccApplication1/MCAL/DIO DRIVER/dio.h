/*
 * dio.h
 * Created: 09/12/2022 09:03:11 م
 *  Author: omarh
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/std_types.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

/*						All Driver Function Prototypes                  */

/* Name	: DIO Initialization 
 * Function : it takes 3 inputs and return void (error handling)
 */
void DIO_initial(uint8_t port_Number , uint8_t pin_Number , uint8_t direction);

/* Name	: DIO Write
 * Function : it takes 3 inputs and return void (error handling) (write on the dio pins)
 */
void DIO_write(uint8_t port_Number , uint8_t pin_Number , uint8_t value);

/* Name	: DIO Toggle 
 * Function : it takes 2 inputs and return void (error handling) (toggle the dio pins)
 */
void DIO_toggle(uint8_t port_Number , uint8_t pin_Number);

/* Name	: DIO Read
 * Function : it takes 3 inputs and return void (error handling) (read the value of dio pins)
 */
void DIO_read(uint8_t port_Number , uint8_t pin_Number , uint8_t *value);




#endif /* DIO_H_ */