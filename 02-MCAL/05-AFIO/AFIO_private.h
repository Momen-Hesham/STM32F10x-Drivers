#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];// instead of define EXTICR0,EXTICR1,EXTICR2,EXTICR3
	volatile uint32 MAPR3;
}AFIO_t;

#define AFIO ((volatile AFIO_t *) 0x40010000)
#endif 
