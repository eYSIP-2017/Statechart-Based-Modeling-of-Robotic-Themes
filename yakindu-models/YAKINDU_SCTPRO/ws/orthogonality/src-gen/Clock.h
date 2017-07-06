
#ifndef CLOCK_H_
#define CLOCK_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'clock'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Clock_main_region_watch,
	Clock_main_region_watch_x_zero,
	Clock_main_region_watch_x_one,
	Clock_main_region_watch_y_zero,
	Clock_main_region_watch_y_one,
	Clock_last_state
} ClockStates;

/*! Type definition of the data structure for the ClockIfaceInput interface scope. */
typedef struct
{
	sc_boolean a_raised;
} ClockIfaceInput;

/*! Type definition of the data structure for the ClockInternal interface scope. */
typedef struct
{
	sc_boolean b_raised;
} ClockInternal;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define CLOCK_MAX_ORTHOGONAL_STATES 2

/*! 
 * Type definition of the data structure for the Clock state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ClockStates stateConfVector[CLOCK_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ClockIfaceInput ifaceInput;
	ClockInternal internal;
} Clock;

/*! Initializes the Clock state machine data structures. Must be called before first usage.*/
extern void clock_init(Clock* handle);

/*! Activates the state machine */
extern void clock_enter(Clock* handle);

/*! Deactivates the state machine */
extern void clock_exit(Clock* handle);

/*! Performs a 'run to completion' step. */
extern void clock_runCycle(Clock* handle);


/*! Raises the in event 'a' that is defined in the interface scope 'Input'. */ 
extern void clockIfaceInput_raise_a(Clock* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean clock_isActive(const Clock* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean clock_isFinal(const Clock* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean clock_isStateActive(const Clock* handle, ClockStates state);

#ifdef __cplusplus
}
#endif 

#endif /* CLOCK_H_ */
