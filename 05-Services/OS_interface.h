/*********************************/
/* Author	: Mo'men Hesham 	 */
/* Version	: V01				 */
/*********************************/


#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H



void SOS_voidCreateTask(uint8 Copy_uint8ID,uint16 Copy_uint16Priodicity,void (*Copy_ptr)(void),uint8 Copy_uint8FirstDelay);
void SOS_voidStart(void);
void SOS_voidSuspendTask(uint8 Copy_uint8ID);
void SOS_voidResumeTask(uint8 Copy_uint8ID);
void SOS_voidClearTask(uint8 Copy_uint8ID);


#endif
