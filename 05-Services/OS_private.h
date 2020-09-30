/*********************************/
/* Author	: Mo'men Hesham 	 */
/* Version	: V01				 */
/*********************************/


#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define TASK_READY		1
#define TASK_SUSPEND	2
#define TASK_DELETED	3

typedef struct
{
	uint16 priodicity;
	void (*Func_ptr)(void);
	uint8 FirstDelay;
	uint8 State;
	
	
	
}Task;



#endif
