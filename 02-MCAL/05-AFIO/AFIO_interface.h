#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define EXTI_PORTA	0b0000
#define EXTI_PORTB	0b0001
#define EXTI_PORTC	0b0010

void MAFIO_voidSetEXTIConfiguration(uint8 copy_uint8Line, uint8 copy_uint8PortMap);


#endif
