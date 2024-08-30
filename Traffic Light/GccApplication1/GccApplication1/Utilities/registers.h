/*
 * registers.h
 *
 * Created: 09/12/2022 09:05:05 م
 *  Author: omarh
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"

//DIO REGISTERS


//PORTA REGISTERS
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)


//PORTB REGISTERS
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)


//PORTC REGISTERS
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)



//PORTD REGISTERS
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


//TIMER REGISTERS

#define TIFR   *((volatile uint8_t*)0x58)

// Timer 0 Registers
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)


// Timer 2 Registers
#define TCCR2  *((volatile uint8_t*)0x45)
#define TCNT2  *((volatile uint8_t*)0x44)


//Interrupt Registers
#define MCUCR	*((volatile uint8_t*)0x55)
#define GICR	*((volatile uint8_t*)0x5B)
#define SREG	*((volatile uint8_t*)0x5F)
#define TIMSK	*((volatile uint8_t*)0x59)

#endif /* REGISTERS_H_ */