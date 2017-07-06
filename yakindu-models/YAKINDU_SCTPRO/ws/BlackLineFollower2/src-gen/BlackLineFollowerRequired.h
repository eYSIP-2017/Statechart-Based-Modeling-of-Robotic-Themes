
#ifndef BLACKLINEFOLLOWERREQUIRED_H_
#define BLACKLINEFOLLOWERREQUIRED_H_

#include "..\src\sc_types.h"
#include "BlackLineFollower.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- blackLineFollowerIfaceInput_forward
	- blackLineFollowerIfaceInput_right
	- blackLineFollowerIfaceInput_left
	- blackLineFollowerIfaceInput_stop
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void blackLineFollowerIfaceInput_forward(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_right(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_left(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_stop(const BlackLineFollower* handle);




#ifdef __cplusplus
}
#endif 

#endif /* BLACKLINEFOLLOWERREQUIRED_H_ */
