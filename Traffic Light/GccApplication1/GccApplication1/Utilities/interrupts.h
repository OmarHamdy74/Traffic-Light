/*
 * interrupts.h
 *
 * Created: 09/12/2022 09:06:22 م
 *  Author: omarh
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


//Interrupt Bits Macros			    		

// MCUCR
#define ISC00 0
#define ISC01 1


// GICR
#define INT0 6
#define INT1 7


// SREG
#define GIE 7


//Interrupts	Vectors


#define EXT_INT_0		__vector_1
#define TIMER_2_OVF		__vector_5
#define TIMER0_OVF		__vector_11

#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)



#endif /* INTERRUPTS_H_ */