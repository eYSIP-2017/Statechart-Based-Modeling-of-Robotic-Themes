
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
	- blackLineFollowerIfaceInput_readsensor
	- blackLineFollowerIfaceInput_forward
	- blackLineFollowerIfaceInput_right
	- blackLineFollowerIfaceInput_left
	- blackLineFollowerIfaceInput_orient
	- blackLineFollowerIfaceInput_velocity
	- blackLineFollowerIfaceInput_forward_mm
	- blackLineFollowerIfaceInput_delayms
	- blackLineFollowerIfaceInput_right_degrees
	- blackLineFollowerIfaceInput_left_degrees
	- blackLineFollowerIfaceInput_get_target
	- blackLineFollowerIfaceInput_break
	- blackLineFollowerIfaceInput_soft_left
	- blackLineFollowerIfaceInput_soft_right
	- blackLineFollowerIfaceInput_lcd_print
	- blackLineFollowerIfaceInput_reset_count
	- blackLineFollowerIfaceInput_buzzer_on
	- blackLineFollowerIfaceInput_buzzer_off
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/

extern void blackLineFollowerIfaceInput_readsensor(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_forward(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_right(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_left(const BlackLineFollower* handle);
extern sc_integer blackLineFollowerIfaceInput_orient(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_velocity(const BlackLineFollower* handle, const sc_integer left_motor, const sc_integer right_motor);
extern void blackLineFollowerIfaceInput_forward_mm(const BlackLineFollower* handle, const sc_integer distance);
extern void blackLineFollowerIfaceInput_delayms(const BlackLineFollower* handle, const sc_integer time);
extern void blackLineFollowerIfaceInput_right_degrees(const BlackLineFollower* handle, const sc_integer angle);
extern void blackLineFollowerIfaceInput_left_degrees(const BlackLineFollower* handle, const sc_integer angle);
extern void blackLineFollowerIfaceInput_get_target(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_break(const BlackLineFollower* handle, const sc_integer intensity);
extern void blackLineFollowerIfaceInput_soft_left(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_soft_right(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_lcd_print(const BlackLineFollower* handle, const sc_integer row, const sc_integer column, const sc_integer value, const sc_integer digits);
extern void blackLineFollowerIfaceInput_reset_count(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_buzzer_on(const BlackLineFollower* handle);
extern void blackLineFollowerIfaceInput_buzzer_off(const BlackLineFollower* handle);




#ifdef __cplusplus
}
#endif 

#endif /* BLACKLINEFOLLOWERREQUIRED_H_ */
