
#ifndef PUZZLE_SOLVERREQUIRED_H_
#define PUZZLE_SOLVERREQUIRED_H_

#include "..\src\sc_types.h"
#include "Puzzle_solver.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- puzzle_solverIfaceInput_readsensor
	- puzzle_solverIfaceInput_forward
	- puzzle_solverIfaceInput_right
	- puzzle_solverIfaceInput_left
	- puzzle_solverIfaceInput_orient
	- puzzle_solverIfaceInput_velocity
	- puzzle_solverIfaceInput_forward_mm
	- puzzle_solverIfaceInput_delayms
	- puzzle_solverIfaceInput_right_degrees
	- puzzle_solverIfaceInput_left_degrees
	- puzzle_solverIfaceInput_get_target
	- puzzle_solverIfaceInput_break
	- puzzle_solverIfaceInput_soft_left
	- puzzle_solverIfaceInput_soft_right
	- puzzle_solverIfaceInput_lcd_print
	- puzzle_solverIfaceInput_reset_count
	- puzzle_solverIfaceInput_buzzer_on
	- puzzle_solverIfaceInput_buzzer_off
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/

extern void puzzle_solverIfaceInput_readsensor(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_forward(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_right(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_left(const Puzzle_solver* handle);
extern sc_integer puzzle_solverIfaceInput_orient(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_velocity(const Puzzle_solver* handle, const sc_integer left_motor, const sc_integer right_motor);
extern void puzzle_solverIfaceInput_forward_mm(const Puzzle_solver* handle, const sc_integer distance);
extern void puzzle_solverIfaceInput_delayms(const Puzzle_solver* handle, const sc_integer time);
extern void puzzle_solverIfaceInput_right_degrees(const Puzzle_solver* handle, const sc_integer angle);
extern void puzzle_solverIfaceInput_left_degrees(const Puzzle_solver* handle, const sc_integer angle);
extern void puzzle_solverIfaceInput_get_target(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_break(const Puzzle_solver* handle, const sc_integer intensity);
extern void puzzle_solverIfaceInput_soft_left(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_soft_right(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_lcd_print(const Puzzle_solver* handle, const sc_integer row, const sc_integer column, const sc_integer value, const sc_integer digits);
extern void puzzle_solverIfaceInput_reset_count(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_buzzer_on(const Puzzle_solver* handle);
extern void puzzle_solverIfaceInput_buzzer_off(const Puzzle_solver* handle);




#ifdef __cplusplus
}
#endif 

#endif /* PUZZLE_SOLVERREQUIRED_H_ */
