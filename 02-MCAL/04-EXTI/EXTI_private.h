#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
	
}EXTI_t;

// EXTI is pointer to strucy EXTI_t like example: ptr =(int *) x;
// Da pointer mesh value 3shan a3mlha dereference 


static void (*EXTI_CallBack[16]) (void) ;


#define EXTI	((volatile EXTI_t *) 0x40010400)
 
 
#endif
