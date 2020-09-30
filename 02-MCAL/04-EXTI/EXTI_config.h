#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

// hena el user haye5tar hwa hayesht3,l 3la anhy exti badl ma kan yeb3tlly el line ka parameter lel initialization function

/*Options:	LINE0
			LINE1
			LINE2
			....
*/
	

#define EXTI_LINE	LINE0
// bs wa7ed mn 3yoob el tare2a de eny ma2drsh be nafs el init function a5tar kza line
//e3ny ma2drsh hena a2ol eny hasawy el EXTI_LINE be LINE0 & LINE1 & .... laa lazem a5tar wa7ed bs

/* Options:	RISSING_EDGE
			FALLING_EDGE
			ON_CHANGE
*/
#define EXTI_MODE	FALLING_EDGE

#endif
