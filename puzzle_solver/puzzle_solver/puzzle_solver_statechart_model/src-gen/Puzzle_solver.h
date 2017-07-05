
#ifndef PUZZLE_SOLVER_H_
#define PUZZLE_SOLVER_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'puzzle_solver'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Puzzle_solver_main_PuzzleSolver,
	Puzzle_solver_main_PuzzleSolver_main_start,
	Puzzle_solver_main_PuzzleSolver_main_go_to_pick_node,
	Puzzle_solver_main_PuzzleSolver_main_picking,
	Puzzle_solver_main_PuzzleSolver_main_picking_picking_going_to_middle_of_segment,
	Puzzle_solver_main_PuzzleSolver_main_picking_picking_at_middle_of_segment,
	Puzzle_solver_main_PuzzleSolver_main_going_in_middle_of_d1,
	Puzzle_solver_main_PuzzleSolver_main_going_to_drop_node,
	Puzzle_solver_main_PuzzleSolver_main_dropping,
	Puzzle_solver_main_PuzzleSolver_main_dropping_dropping_going_to_middle_of_segment,
	Puzzle_solver_main_PuzzleSolver_main_dropping_dropping_at_middle_of_segment,
	Puzzle_solver_main_PuzzleSolver_main_going_in_middle_of_d2,
	Puzzle_solver_main_PuzzleSolver_GotoTargetNode_GoingToNextNode,
	Puzzle_solver_main_PuzzleSolver_GotoTargetNode_NodeAction,
	Puzzle_solver_main_PuzzleSolver_GotoTargetNode_NodeAction_ToNextNode_NodeActionInProgress,
	Puzzle_solver_main_PuzzleSolver_GotoTargetNode_NodeAction_ToNextNode_StartNodeAction,
	Puzzle_solver_main_PuzzleSolver_GotoTargetNode_Idle,
	Puzzle_solver_main_PuzzleSolver_Coordinates_Coordinates,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn_s_AllSensorDetectWhite,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOn_s_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine,
	Puzzle_solver_main_PuzzleSolver_LineFollower_LineFollowerOff,
	Puzzle_solver_main_PuzzleSolver_Orientation_East,
	Puzzle_solver_main_PuzzleSolver_Orientation_West,
	Puzzle_solver_main_PuzzleSolver_Orientation_North,
	Puzzle_solver_main_PuzzleSolver_Orientation_South,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOn,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOn_ss_GoingForward,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOn_ss_TurningLeft,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOn_ss_TurningRight,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOn_ss_TurningBack,
	Puzzle_solver_main_PuzzleSolver_Turn_TurningOff,
	Puzzle_solver_main_stop,
	Puzzle_solver_last_state
} Puzzle_solverStates;

/*! Type definition of the data structure for the Puzzle_solverInternal interface scope. */
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
} Puzzle_solverInternal;

/*! Type definition of the data structure for the Puzzle_solverIfaceInput interface scope. */
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
} Puzzle_solverIfaceInput;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PUZZLE_SOLVER_MAX_ORTHOGONAL_STATES 6

/*! 
 * Type definition of the data structure for the Puzzle_solver state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Puzzle_solverStates stateConfVector[PUZZLE_SOLVER_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Puzzle_solverInternal internal;
	Puzzle_solverIfaceInput ifaceInput;
} Puzzle_solver;

/*! Initializes the Puzzle_solver state machine data structures. Must be called before first usage.*/
extern void puzzle_solver_init(Puzzle_solver* handle);

/*! Activates the state machine */
extern void puzzle_solver_enter(Puzzle_solver* handle);

/*! Deactivates the state machine */
extern void puzzle_solver_exit(Puzzle_solver* handle);

/*! Performs a 'run to completion' step. */
extern void puzzle_solver_runCycle(Puzzle_solver* handle);


/*! Gets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_left_sensor(const Puzzle_solver* handle);
/*! Sets the value of the variable 'left_sensor' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_left_sensor(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_right_sensor(const Puzzle_solver* handle);
/*! Sets the value of the variable 'right_sensor' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_right_sensor(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_center_sensor(const Puzzle_solver* handle);
/*! Sets the value of the variable 'center_sensor' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_center_sensor(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'node' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_node(const Puzzle_solver* handle);
/*! Sets the value of the variable 'node' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_node(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'isnode' that is defined in the interface scope 'Input'. */ 
extern sc_boolean puzzle_solverIfaceInput_get_isnode(const Puzzle_solver* handle);
/*! Sets the value of the variable 'isnode' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_isnode(Puzzle_solver* handle, sc_boolean value);
/*! Gets the value of the variable 'left_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean puzzle_solverIfaceInput_get_left_sensed_line(const Puzzle_solver* handle);
/*! Sets the value of the variable 'left_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_left_sensed_line(Puzzle_solver* handle, sc_boolean value);
/*! Gets the value of the variable 'center_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean puzzle_solverIfaceInput_get_center_sensed_line(const Puzzle_solver* handle);
/*! Sets the value of the variable 'center_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_center_sensed_line(Puzzle_solver* handle, sc_boolean value);
/*! Gets the value of the variable 'right_sensed_line' that is defined in the interface scope 'Input'. */ 
extern sc_boolean puzzle_solverIfaceInput_get_right_sensed_line(const Puzzle_solver* handle);
/*! Sets the value of the variable 'right_sensed_line' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_right_sensed_line(Puzzle_solver* handle, sc_boolean value);
/*! Gets the value of the variable 'distance' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_distance(const Puzzle_solver* handle);
/*! Sets the value of the variable 'distance' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_distance(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'num' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_num(const Puzzle_solver* handle);
/*! Sets the value of the variable 'num' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_num(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'x' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_x(const Puzzle_solver* handle);
/*! Sets the value of the variable 'x' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_x(Puzzle_solver* handle, sc_integer value);
/*! Gets the value of the variable 'y' that is defined in the interface scope 'Input'. */ 
extern sc_integer puzzle_solverIfaceInput_get_y(const Puzzle_solver* handle);
/*! Sets the value of the variable 'y' that is defined in the interface scope 'Input'. */ 
extern void puzzle_solverIfaceInput_set_y(Puzzle_solver* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean puzzle_solver_isActive(const Puzzle_solver* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean puzzle_solver_isFinal(const Puzzle_solver* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean puzzle_solver_isStateActive(const Puzzle_solver* handle, Puzzle_solverStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PUZZLE_SOLVER_H_ */
