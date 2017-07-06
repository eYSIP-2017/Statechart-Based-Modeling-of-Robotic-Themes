
#ifndef WHITELINEFOLLOWERREQUIRED_H_
#define WHITELINEFOLLOWERREQUIRED_H_

#include "..\src\sc_types.h"
#include "WhiteLineFollower.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- whiteLineFollowerIfaceInput_forward
	- whiteLineFollowerIfaceInput_right
	- whiteLineFollowerIfaceInput_left
	- whiteLineFollowerIfaceInput_stop
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void whiteLineFollowerIfaceInput_forward(const WhiteLineFollower* handle);
extern void whiteLineFollowerIfaceInput_right(const WhiteLineFollower* handle);
extern void whiteLineFollowerIfaceInput_left(const WhiteLineFollower* handle);
extern void whiteLineFollowerIfaceInput_stop(const WhiteLineFollower* handle);




#ifdef __cplusplus
}
#endif 

#endif /* WHITELINEFOLLOWERREQUIRED_H_ */
