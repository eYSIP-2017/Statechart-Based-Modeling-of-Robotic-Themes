
#ifndef BLACKLINEFOLLOWER_H_
#define BLACKLINEFOLLOWER_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'BlackLineFollower'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	BlackLineFollower_main_region_linefollowing,
	BlackLineFollower_main_region_linefollowing_r1_right_detects_line,
	BlackLineFollower_main_region_linefollowing_r1_center_detects_line,
	BlackLineFollower_main_region_linefollowing_r1_left_detects_line,
	BlackLineFollower_main_region_linefollowing_r1_none_detects_line,
	BlackLineFollower_main_region_OnNode,
	BlackLineFollower_last_state
} BlackLineFollowerStates;

/*! Type definition of the data structure for the BlackLineFollowerIfaceInput interface scope. */
typedef struct
{
	sc_integer left_sensor;
	sc_integer right_sensor;
	sc_integer center_sensor;
	sc_integer node;
	sc_boolean isnode;
} BlackLineFollowerIfaceInput;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the BlackLineFollower state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	BlackLineFollowerStates stateConfVector[BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	BlackLineFollowerIfaceInput ifaceInput;
} BlackLineFollower;

/*! Initializes the BlackLineFollower state machine data structures. Must be called before first usage.*/
extern void blackLineFollower_init(BlackLineFollower* handle);

/*! Activates the state machine */
extern void blackLineFollower_enter(BlackLineFollower* handle);

/*! Deactivates the state machine */
extern void blackLineFollower_exit(BlackLineFollower* handle);

/*! Performs a 'run to completion' step. */
extern void blackLineFollower_runCycle(BlackLineFollower* handle);


/*! Gets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_left_sensor(const BlackLineFollower* handle);
/*! Sets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_left_sensor(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_right_sensor(const BlackLineFollower* handle);
/*! Sets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_right_sensor(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_center_sensor(const BlackLineFollower* handle);
/*! Sets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_center_sensor(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'node' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_node(const BlackLineFollower* handle);
/*! Sets the value of the variable 'node' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_node(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'isnode' that is defined in the interface scope 'Input'. */ 
extern sc_boolean blackLineFollowerIfaceInput_get_isnode(const BlackLineFollower* handle);
/*! Sets the value of the variable 'isnode' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_isnode(BlackLineFollower* handle, sc_boolean value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blackLineFollower_isActive(const BlackLineFollower* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blackLineFollower_isFinal(const BlackLineFollower* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blackLineFollower_isStateActive(const BlackLineFollower* handle, BlackLineFollowerStates state);

#ifdef __cplusplus
}
#endif 

#endif /* BLACKLINEFOLLOWER_H_ */
