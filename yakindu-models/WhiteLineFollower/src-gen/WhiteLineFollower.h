
#ifndef WHITELINEFOLLOWER_H_
#define WHITELINEFOLLOWER_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'WhiteLineFollower'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	WhiteLineFollower_main_region_OnLine,
	WhiteLineFollower_main_region_LeftOfLine,
	WhiteLineFollower_main_region_RightOfLine,
	WhiteLineFollower_main_region_OutOfLine,
	WhiteLineFollower_last_state
} WhiteLineFollowerStates;

/*! Type definition of the data structure for the WhiteLineFollowerIfaceInput interface scope. */
typedef struct
{
	sc_integer left_sensor;
	sc_integer right_sensor;
	sc_integer center_sensor;
} WhiteLineFollowerIfaceInput;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define WHITELINEFOLLOWER_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the WhiteLineFollower state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	WhiteLineFollowerStates stateConfVector[WHITELINEFOLLOWER_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	WhiteLineFollowerIfaceInput ifaceInput;
} WhiteLineFollower;

/*! Initializes the WhiteLineFollower state machine data structures. Must be called before first usage.*/
extern void whiteLineFollower_init(WhiteLineFollower* handle);

/*! Activates the state machine */
extern void whiteLineFollower_enter(WhiteLineFollower* handle);

/*! Deactivates the state machine */
extern void whiteLineFollower_exit(WhiteLineFollower* handle);

/*! Performs a 'run to completion' step. */
extern void whiteLineFollower_runCycle(WhiteLineFollower* handle);


/*! Gets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer whiteLineFollowerIfaceInput_get_left_sensor(const WhiteLineFollower* handle);
/*! Sets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern void whiteLineFollowerIfaceInput_set_left_sensor(WhiteLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer whiteLineFollowerIfaceInput_get_right_sensor(const WhiteLineFollower* handle);
/*! Sets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern void whiteLineFollowerIfaceInput_set_right_sensor(WhiteLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer whiteLineFollowerIfaceInput_get_center_sensor(const WhiteLineFollower* handle);
/*! Sets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern void whiteLineFollowerIfaceInput_set_center_sensor(WhiteLineFollower* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean whiteLineFollower_isActive(const WhiteLineFollower* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean whiteLineFollower_isFinal(const WhiteLineFollower* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean whiteLineFollower_isStateActive(const WhiteLineFollower* handle, WhiteLineFollowerStates state);

#ifdef __cplusplus
}
#endif 

#endif /* WHITELINEFOLLOWER_H_ */
