
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
	BlackLineFollower_main_PuzzleSolver,
	BlackLineFollower_main_PuzzleSolver_main_start,
	BlackLineFollower_main_PuzzleSolver_main_go_to_pick_node,
	BlackLineFollower_main_PuzzleSolver_main_picking,
	BlackLineFollower_main_PuzzleSolver_main_picking_picking_going_to_middle_of_segment,
	BlackLineFollower_main_PuzzleSolver_main_picking_picking_at_middle_of_segment,
	BlackLineFollower_main_PuzzleSolver_main_going_in_middle_of_d1,
	BlackLineFollower_main_PuzzleSolver_main_going_to_drop_node,
	BlackLineFollower_main_PuzzleSolver_main_dropping,
	BlackLineFollower_main_PuzzleSolver_main_dropping_dropping_going_to_middle_of_segment,
	BlackLineFollower_main_PuzzleSolver_main_dropping_dropping_at_middle_of_segment,
	BlackLineFollower_main_PuzzleSolver_main_going_in_middle_of_d2,
	BlackLineFollower_main_PuzzleSolver_GotoTargetNode_GoingToNextNode,
	BlackLineFollower_main_PuzzleSolver_GotoTargetNode_NodeAction,
	BlackLineFollower_main_PuzzleSolver_GotoTargetNode_NodeAction_ToNextNode_NodeActionInProgress,
	BlackLineFollower_main_PuzzleSolver_GotoTargetNode_NodeAction_ToNextNode_StartNodeAction,
	BlackLineFollower_main_PuzzleSolver_GotoTargetNode_Idle,
	BlackLineFollower_main_PuzzleSolver_Coordinates_Coordinates,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn_s_AllSensorDetectWhite,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine,
	BlackLineFollower_main_PuzzleSolver_LineFollower_LineFollowerOff,
	BlackLineFollower_main_PuzzleSolver_Orientation_East,
	BlackLineFollower_main_PuzzleSolver_Orientation_West,
	BlackLineFollower_main_PuzzleSolver_Orientation_North,
	BlackLineFollower_main_PuzzleSolver_Orientation_South,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOn,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOn_ss_GoingForward,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOn_ss_TurningLeft,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOn_ss_TurningRight,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOn_ss_TurningBack,
	BlackLineFollower_main_PuzzleSolver_Turn_TurningOff,
	BlackLineFollower_main_stop,
	BlackLineFollower_last_state
} BlackLineFollowerStates;

/*! Type definition of the data structure for the BlackLineFollowerInternal interface scope. */
typedef struct
{
	sc_boolean StartLineFollower_raised;
	sc_boolean StopLineFollower_raised;
	sc_boolean StartTurning_raised;
	sc_boolean OrientInEast_raised;
	sc_boolean OrientInWest_raised;
	sc_boolean OrientInNorth_raised;
	sc_boolean OrientInSouth_raised;
	sc_boolean back_raised;
	sc_boolean left_raised;
	sc_boolean right_raised;
	sc_boolean front_raised;
	sc_boolean UpdateCoordinates_raised;
	sc_boolean gotoxy_raised;
	sc_string turn;
	sc_integer x;
	sc_integer y;
	sc_integer tx;
	sc_integer ty;
} BlackLineFollowerInternal;

/*! Type definition of the data structure for the BlackLineFollowerIfaceInput interface scope. */
typedef struct
{
	sc_integer left_sensor;
	sc_integer right_sensor;
	sc_integer center_sensor;
	sc_integer node;
	sc_boolean isnode;
	sc_boolean left_sensed_line;
	sc_boolean center_sensed_line;
	sc_boolean right_sensed_line;
	sc_integer distance;
	sc_integer num;
	sc_integer x;
	sc_integer y;
} BlackLineFollowerIfaceInput;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES 6

/*! 
 * Type definition of the data structure for the BlackLineFollower state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	BlackLineFollowerStates stateConfVector[BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	BlackLineFollowerInternal internal;
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
/*! Gets the value of the variable 'left_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean blackLineFollowerIfaceInput_get_left_sensed_line(const BlackLineFollower* handle);
/*! Sets the value of the variable 'left_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_left_sensed_line(BlackLineFollower* handle, sc_boolean value);
/*! Gets the value of the variable 'center_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean blackLineFollowerIfaceInput_get_center_sensed_line(const BlackLineFollower* handle);
/*! Sets the value of the variable 'center_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_center_sensed_line(BlackLineFollower* handle, sc_boolean value);
/*! Gets the value of the variable 'right_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean blackLineFollowerIfaceInput_get_right_sensed_line(const BlackLineFollower* handle);
/*! Sets the value of the variable 'right_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_right_sensed_line(BlackLineFollower* handle, sc_boolean value);
/*! Gets the value of the variable 'distance' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_distance(const BlackLineFollower* handle);
/*! Sets the value of the variable 'distance' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_distance(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'num' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_num(const BlackLineFollower* handle);
/*! Sets the value of the variable 'num' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_num(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'x' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_x(const BlackLineFollower* handle);
/*! Sets the value of the variable 'x' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_x(BlackLineFollower* handle, sc_integer value);
/*! Gets the value of the variable 'y' that is defined in the interface scope 'Input'. */ 
extern sc_integer blackLineFollowerIfaceInput_get_y(const BlackLineFollower* handle);
/*! Sets the value of the variable 'y' that is defined in the interface scope 'Input'. */ 
extern void blackLineFollowerIfaceInput_set_y(BlackLineFollower* handle, sc_integer value);

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
