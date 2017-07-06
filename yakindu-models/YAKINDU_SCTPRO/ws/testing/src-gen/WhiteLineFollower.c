
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "WhiteLineFollower.h"
#include "WhiteLineFollowerRequired.h"
/*! \file Implementation of the state machine 'WhiteLineFollower'
*/

/* prototypes of all internal functions */
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1_tr1(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2_tr2(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1_tr1(const WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle);
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_default(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1__entry_Default(WhiteLineFollower* handle);
static void whiteLineFollower_react_LineFollower__entry_Default(WhiteLineFollower* handle);
static void whiteLineFollower_clearInEvents(WhiteLineFollower* handle);
static void whiteLineFollower_clearOutEvents(WhiteLineFollower* handle);


void whiteLineFollower_init(WhiteLineFollower* handle)
{
	sc_integer i;

	for (i = 0; i < WHITELINEFOLLOWER_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = WhiteLineFollower_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	whiteLineFollower_clearInEvents(handle);
	whiteLineFollower_clearOutEvents(handle);

	/* Default init sequence for statechart WhiteLineFollower */
	handle->ifaceInput.center_sensor = 0;
	handle->ifaceInput.left_sensor = 0;
	handle->ifaceInput.right_sensor = 0;
	handle->ifaceInput.isnode = bool_false;

}

void whiteLineFollower_enter(WhiteLineFollower* handle)
{
	/* Default enter sequence for statechart WhiteLineFollower */
	whiteLineFollower_enseq_LineFollower_default(handle);
}

void whiteLineFollower_exit(WhiteLineFollower* handle)
{
	/* Default exit sequence for statechart WhiteLineFollower */
	whiteLineFollower_exseq_LineFollower(handle);
}

sc_boolean whiteLineFollower_isActive(const WhiteLineFollower* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != WhiteLineFollower_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean whiteLineFollower_isFinal(const WhiteLineFollower* handle)
{
   return bool_false;
}

static void whiteLineFollower_clearInEvents(WhiteLineFollower* handle)
{
	handle->internal.StartLineFollower_raised = bool_false;
	handle->internal.StopLineFollower_raised = bool_false;
}

static void whiteLineFollower_clearOutEvents(WhiteLineFollower* handle)
{
}

void whiteLineFollower_runCycle(WhiteLineFollower* handle)
{
	
	whiteLineFollower_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < WHITELINEFOLLOWER_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite :
		{
			whiteLineFollower_react_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine :
		{
			whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine :
		{
			whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine :
		{
			whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
			break;
		}
		default:
			break;
		}
	}
	
	whiteLineFollower_clearInEvents(handle);
}


sc_boolean whiteLineFollower_isStateActive(const WhiteLineFollower* handle, WhiteLineFollowerStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case WhiteLineFollower_LineFollower_LineFollowerOn :
			result = (sc_boolean) (handle->stateConfVector[0] >= WhiteLineFollower_LineFollower_LineFollowerOn
				&& handle->stateConfVector[0] <= WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine);
			break;
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite
			);
			break;
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine :
			result = (sc_boolean) (handle->stateConfVector[0] >= WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine
				&& handle->stateConfVector[0] <= WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine);
			break;
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine
			);
			break;
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine
			);
			break;
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



sc_integer whiteLineFollowerIfaceInput_get_center_sensor(const WhiteLineFollower* handle)
{
	return handle->ifaceInput.center_sensor;
}
void whiteLineFollowerIfaceInput_set_center_sensor(WhiteLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.center_sensor = value;
}
sc_integer whiteLineFollowerIfaceInput_get_left_sensor(const WhiteLineFollower* handle)
{
	return handle->ifaceInput.left_sensor;
}
void whiteLineFollowerIfaceInput_set_left_sensor(WhiteLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.left_sensor = value;
}
sc_integer whiteLineFollowerIfaceInput_get_right_sensor(const WhiteLineFollower* handle)
{
	return handle->ifaceInput.right_sensor;
}
void whiteLineFollowerIfaceInput_set_right_sensor(WhiteLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.right_sensor = value;
}
sc_boolean whiteLineFollowerIfaceInput_get_isnode(const WhiteLineFollower* handle)
{
	return handle->ifaceInput.isnode;
}
void whiteLineFollowerIfaceInput_set_isnode(WhiteLineFollower* handle, sc_boolean value)
{
	handle->ifaceInput.isnode = value;
}

/* implementations of all internal functions */

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2_tr2(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return ((handle->ifaceInput.left_sensor < 40 && handle->ifaceInput.center_sensor < 40 && handle->ifaceInput.right_sensor < 40) || handle->ifaceInput.isnode) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor > 40) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor > 40) ? bool_true : bool_false;
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_default(handle);
}

static void whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_default(handle);
}

/* Entry action for state 'AllSensorDetectWhite'. */
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle)
{
	/* Entry action for state 'AllSensorDetectWhite'. */
	whiteLineFollowerIfaceInput_velocity(handle, 180, 180);
}

/* Entry action for state 'RightSensorOnLine'. */
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'RightSensorOnLine'. */
	whiteLineFollowerIfaceInput_velocity(handle, 100, 0);
}

/* Entry action for state 'LeftSensorOnLine'. */
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'LeftSensorOnLine'. */
	whiteLineFollowerIfaceInput_velocity(handle, 0, 100);
}

/* Entry action for state 'CenterSensorOnLine'. */
static void whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'CenterSensorOnLine'. */
	whiteLineFollowerIfaceInput_velocity(handle, 100, 0);
}

/* 'default' enter sequence for state LineFollowerOn */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state LineFollowerOn */
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_default(handle);
}

/* 'default' enter sequence for state AllSensorDetectWhite */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state AllSensorDetectWhite */
	whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
	handle->stateConfVector[0] = WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state RightSensorOnLine */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state RightSensorOnLine */
	whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LeftSensorOnLine */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state LeftSensorOnLine */
	whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state CenterSensorOnLine */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state CenterSensorOnLine */
	whiteLineFollower_enact_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region LineFollower */
static void whiteLineFollower_enseq_LineFollower_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for region LineFollower */
	whiteLineFollower_react_LineFollower__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for region r1 */
	whiteLineFollower_react_LineFollower_LineFollowerOn_r1__entry_Default(handle);
}

/* Default exit sequence for state AllSensorDetectWhite */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle)
{
	/* Default exit sequence for state AllSensorDetectWhite */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine */
	whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region(handle);
}

/* Default exit sequence for state RightSensorOnLine */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state RightSensorOnLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LeftSensorOnLine */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state LeftSensorOnLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state CenterSensorOnLine */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state CenterSensorOnLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region LineFollower */
static void whiteLineFollower_exseq_LineFollower(WhiteLineFollower* handle)
{
	/* Default exit sequence for region LineFollower */
	/* Handle exit of all possible states (of WhiteLineFollower.LineFollower) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1(WhiteLineFollower* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of WhiteLineFollower.LineFollower.LineFollowerOn.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region inner region */
static void whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region(WhiteLineFollower* handle)
{
	/* Default exit sequence for region inner region */
	/* Handle exit of all possible states (of WhiteLineFollower.LineFollower.LineFollowerOn.r1.Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine.inner_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(handle);
			break;
		}
		case WhiteLineFollower_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine :
		{
			whiteLineFollower_exseq_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state AllSensorDetectWhite. */
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite(WhiteLineFollower* handle)
{
	/* The reactions of state AllSensorDetectWhite. */
	if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1_tr1(handle) == bool_true)
		{ 
			whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr1(handle);
		}  else
		{
			if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2_tr2(handle) == bool_true)
			{ 
				whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_tr2(handle);
			} 
		}
	}
}

/* The reactions of state RightSensorOnLine. */
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine(WhiteLineFollower* handle)
{
	/* The reactions of state RightSensorOnLine. */
	if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0_tr0(handle) == bool_true)
		{ 
			whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_RightSensorOnLine_tr0(handle);
		} 
	}
}

/* The reactions of state LeftSensorOnLine. */
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine(WhiteLineFollower* handle)
{
	/* The reactions of state LeftSensorOnLine. */
	if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0_tr0(handle) == bool_true)
		{ 
			whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_LeftSensorOnLine_tr0(handle);
		} 
	}
}

/* The reactions of state CenterSensorOnLine. */
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine(WhiteLineFollower* handle)
{
	/* The reactions of state CenterSensorOnLine. */
	if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0_tr0(handle) == bool_true)
		{ 
			whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr0(handle);
		}  else
		{
			if (whiteLineFollower_check_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1_tr1(handle) == bool_true)
			{ 
				whiteLineFollower_effect_LineFollower_LineFollowerOn_r1_Composite_RightSensorOnLine_LeftSensorOnLine_CenterSensorOnLine_inner_region_CenterSensorOnLine_tr1(handle);
			} 
		}
	}
}

/* Default react sequence for initial entry  */
static void whiteLineFollower_react_LineFollower_LineFollowerOn_r1__entry_Default(WhiteLineFollower* handle)
{
	/* Default react sequence for initial entry  */
	whiteLineFollowerIfaceInput_forward(handle);
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_r1_AllSensorDetectWhite_default(handle);
}

/* Default react sequence for initial entry  */
static void whiteLineFollower_react_LineFollower__entry_Default(WhiteLineFollower* handle)
{
	/* Default react sequence for initial entry  */
	whiteLineFollower_enseq_LineFollower_LineFollowerOn_default(handle);
}


