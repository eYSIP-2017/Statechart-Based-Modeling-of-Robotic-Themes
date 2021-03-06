
#ifndef BUZZERREQUIRED_H_
#define BUZZERREQUIRED_H_

#include "..\src\sc_types.h"
#include "Buzzer.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- buzzerIfaceInput_buzzer_on
	- buzzerIfaceInput_buzzer_off
	- buzzerIfaceInput_wait
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void buzzerIfaceInput_buzzer_on(const Buzzer* handle);
extern void buzzerIfaceInput_buzzer_off(const Buzzer* handle);
extern void buzzerIfaceInput_wait(const Buzzer* handle, const sc_integer x);




#ifdef __cplusplus
}
#endif 

#endif /* BUZZERREQUIRED_H_ */
