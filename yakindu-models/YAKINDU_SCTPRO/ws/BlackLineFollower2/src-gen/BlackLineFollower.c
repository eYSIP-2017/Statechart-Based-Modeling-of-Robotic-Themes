
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "BlackLineFollower.h"
#include "BlackLineFollowerRequired.h"
/*! \file Implementation of the state machine 'BlackLineFollower'
*/

/* prototypes of all internal functions */
static sc_boolean blackLineFollower_check_main_region_linefollowing_tr0_tr0(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_right_detects_line_tr0_tr0(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr0_tr0(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr1_tr1(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr2_tr2(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr0_tr0(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr1_tr1(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr0_tr0(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr1_tr1(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr2_tr2(const BlackLineFollower* handle);
static sc_boolean blackLineFollower_check_main_region_OnNode_tr0_tr0(const BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_tr0(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_right_detects_line_tr0(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr0(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr1(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr2(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr0(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr1(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr0(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr1(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr2(BlackLineFollower* handle);
static void blackLineFollower_effect_main_region_OnNode_tr0(BlackLineFollower* handle);
static void blackLineFollower_enact_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle);
static void blackLineFollower_enact_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle);
static void blackLineFollower_enact_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle);
static void blackLineFollower_enact_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle);
static void blackLineFollower_enact_main_region_OnNode(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_r1_right_detects_line_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_r1_center_detects_line_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_r1_left_detects_line_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_r1_none_detects_line_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_OnNode_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_default(BlackLineFollower* handle);
static void blackLineFollower_enseq_main_region_linefollowing_r1_default(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_OnNode(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region(BlackLineFollower* handle);
static void blackLineFollower_exseq_main_region_linefollowing_r1(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_OnNode(BlackLineFollower* handle);
static void blackLineFollower_react_main_region__entry_Default(BlackLineFollower* handle);
static void blackLineFollower_react_main_region_linefollowing_r1__entry_Default(BlackLineFollower* handle);
static void blackLineFollower_clearInEvents(BlackLineFollower* handle);
static void blackLineFollower_clearOutEvents(BlackLineFollower* handle);


void blackLineFollower_init(BlackLineFollower* handle)
{
	sc_integer i;

	for (i = 0; i < BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = BlackLineFollower_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	blackLineFollower_clearInEvents(handle);
	blackLineFollower_clearOutEvents(handle);

	/* Default init sequence for statechart BlackLineFollower */
	handle->ifaceInput.left_sensor = 0;
	handle->ifaceInput.right_sensor = 0;
	handle->ifaceInput.center_sensor = 0;
	handle->ifaceInput.node = 0;
	handle->ifaceInput.isnode = bool_false;

}

void blackLineFollower_enter(BlackLineFollower* handle)
{
	/* Default enter sequence for statechart BlackLineFollower */
	blackLineFollower_enseq_main_region_default(handle);
}

void blackLineFollower_exit(BlackLineFollower* handle)
{
	/* Default exit sequence for statechart BlackLineFollower */
	blackLineFollower_exseq_main_region(handle);
}

sc_boolean blackLineFollower_isActive(const BlackLineFollower* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != BlackLineFollower_last_state)
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
sc_boolean blackLineFollower_isFinal(const BlackLineFollower* handle)
{
   return bool_false;
}

static void blackLineFollower_clearInEvents(BlackLineFollower* handle)
{
}

static void blackLineFollower_clearOutEvents(BlackLineFollower* handle)
{
}

void blackLineFollower_runCycle(BlackLineFollower* handle)
{
	
	blackLineFollower_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < BLACKLINEFOLLOWER_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case BlackLineFollower_main_region_linefollowing_r1_right_detects_line :
		{
			blackLineFollower_react_main_region_linefollowing_r1_right_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_center_detects_line :
		{
			blackLineFollower_react_main_region_linefollowing_r1_center_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_left_detects_line :
		{
			blackLineFollower_react_main_region_linefollowing_r1_left_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_none_detects_line :
		{
			blackLineFollower_react_main_region_linefollowing_r1_none_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_OnNode :
		{
			blackLineFollower_react_main_region_OnNode(handle);
			break;
		}
		default:
			break;
		}
	}
	
	blackLineFollower_clearInEvents(handle);
}


sc_boolean blackLineFollower_isStateActive(const BlackLineFollower* handle, BlackLineFollowerStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case BlackLineFollower_main_region_linefollowing :
			result = (sc_boolean) (handle->stateConfVector[0] >= BlackLineFollower_main_region_linefollowing
				&& handle->stateConfVector[0] <= BlackLineFollower_main_region_linefollowing_r1_none_detects_line);
			break;
		case BlackLineFollower_main_region_linefollowing_r1_right_detects_line :
			result = (sc_boolean) (handle->stateConfVector[0] == BlackLineFollower_main_region_linefollowing_r1_right_detects_line
			);
			break;
		case BlackLineFollower_main_region_linefollowing_r1_center_detects_line :
			result = (sc_boolean) (handle->stateConfVector[0] == BlackLineFollower_main_region_linefollowing_r1_center_detects_line
			);
			break;
		case BlackLineFollower_main_region_linefollowing_r1_left_detects_line :
			result = (sc_boolean) (handle->stateConfVector[0] == BlackLineFollower_main_region_linefollowing_r1_left_detects_line
			);
			break;
		case BlackLineFollower_main_region_linefollowing_r1_none_detects_line :
			result = (sc_boolean) (handle->stateConfVector[0] == BlackLineFollower_main_region_linefollowing_r1_none_detects_line
			);
			break;
		case BlackLineFollower_main_region_OnNode :
			result = (sc_boolean) (handle->stateConfVector[0] == BlackLineFollower_main_region_OnNode
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



sc_integer blackLineFollowerIfaceInput_get_left_sensor(const BlackLineFollower* handle)
{
	return handle->ifaceInput.left_sensor;
}
void blackLineFollowerIfaceInput_set_left_sensor(BlackLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.left_sensor = value;
}
sc_integer blackLineFollowerIfaceInput_get_right_sensor(const BlackLineFollower* handle)
{
	return handle->ifaceInput.right_sensor;
}
void blackLineFollowerIfaceInput_set_right_sensor(BlackLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.right_sensor = value;
}
sc_integer blackLineFollowerIfaceInput_get_center_sensor(const BlackLineFollower* handle)
{
	return handle->ifaceInput.center_sensor;
}
void blackLineFollowerIfaceInput_set_center_sensor(BlackLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.center_sensor = value;
}
sc_integer blackLineFollowerIfaceInput_get_node(const BlackLineFollower* handle)
{
	return handle->ifaceInput.node;
}
void blackLineFollowerIfaceInput_set_node(BlackLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.node = value;
}
sc_boolean blackLineFollowerIfaceInput_get_isnode(const BlackLineFollower* handle)
{
	return handle->ifaceInput.isnode;
}
void blackLineFollowerIfaceInput_set_isnode(BlackLineFollower* handle, sc_boolean value)
{
	handle->ifaceInput.isnode = value;
}

/* implementations of all internal functions */

static sc_boolean blackLineFollower_check_main_region_linefollowing_tr0_tr0(const BlackLineFollower* handle)
{
	return handle->ifaceInput.isnode;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_right_detects_line_tr0_tr0(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 20) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr0_tr0(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr1_tr1(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr2_tr2(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor < 20) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr0_tr0(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 20) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr1_tr1(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr0_tr0(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr1_tr1(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr2_tr2(const BlackLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 20) ? bool_true : bool_false;
}

static sc_boolean blackLineFollower_check_main_region_OnNode_tr0_tr0(const BlackLineFollower* handle)
{
	return (!handle->ifaceInput.isnode) ? bool_true : bool_false;
}

static void blackLineFollower_effect_main_region_linefollowing_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing(handle);
	blackLineFollower_enseq_main_region_OnNode_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_right_detects_line_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_right_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_center_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_left_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr1(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_right_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr2(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_none_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_center_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr1(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_none_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_left_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr1(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_right_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr2(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(handle);
	blackLineFollower_enseq_main_region_linefollowing_r1_center_detects_line_default(handle);
}

static void blackLineFollower_effect_main_region_OnNode_tr0(BlackLineFollower* handle)
{
	blackLineFollower_exseq_main_region_OnNode(handle);
	handle->ifaceInput.node += 1;
	blackLineFollower_enseq_main_region_linefollowing_default(handle);
}

/* Entry action for state 'right detects line'. */
static void blackLineFollower_enact_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle)
{
	/* Entry action for state 'right detects line'. */
	blackLineFollowerIfaceInput_right(handle);
}

/* Entry action for state 'center detects line'. */
static void blackLineFollower_enact_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle)
{
	/* Entry action for state 'center detects line'. */
	blackLineFollowerIfaceInput_right(handle);
}

/* Entry action for state 'left detects line'. */
static void blackLineFollower_enact_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle)
{
	/* Entry action for state 'left detects line'. */
	blackLineFollowerIfaceInput_left(handle);
}

/* Entry action for state 'none detects line'. */
static void blackLineFollower_enact_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle)
{
	/* Entry action for state 'none detects line'. */
	blackLineFollowerIfaceInput_forward(handle);
}

/* Entry action for state 'OnNode'. */
static void blackLineFollower_enact_main_region_OnNode(BlackLineFollower* handle)
{
	/* Entry action for state 'OnNode'. */
	blackLineFollowerIfaceInput_stop(handle);
}

/* 'default' enter sequence for state linefollowing */
static void blackLineFollower_enseq_main_region_linefollowing_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state linefollowing */
	blackLineFollower_enseq_main_region_linefollowing_r1_default(handle);
}

/* 'default' enter sequence for state right detects line */
static void blackLineFollower_enseq_main_region_linefollowing_r1_right_detects_line_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state right detects line */
	blackLineFollower_enact_main_region_linefollowing_r1_right_detects_line(handle);
	handle->stateConfVector[0] = BlackLineFollower_main_region_linefollowing_r1_right_detects_line;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state center detects line */
static void blackLineFollower_enseq_main_region_linefollowing_r1_center_detects_line_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state center detects line */
	blackLineFollower_enact_main_region_linefollowing_r1_center_detects_line(handle);
	handle->stateConfVector[0] = BlackLineFollower_main_region_linefollowing_r1_center_detects_line;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state left detects line */
static void blackLineFollower_enseq_main_region_linefollowing_r1_left_detects_line_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state left detects line */
	blackLineFollower_enact_main_region_linefollowing_r1_left_detects_line(handle);
	handle->stateConfVector[0] = BlackLineFollower_main_region_linefollowing_r1_left_detects_line;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state none detects line */
static void blackLineFollower_enseq_main_region_linefollowing_r1_none_detects_line_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state none detects line */
	blackLineFollower_enact_main_region_linefollowing_r1_none_detects_line(handle);
	handle->stateConfVector[0] = BlackLineFollower_main_region_linefollowing_r1_none_detects_line;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OnNode */
static void blackLineFollower_enseq_main_region_OnNode_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for state OnNode */
	blackLineFollower_enact_main_region_OnNode(handle);
	handle->stateConfVector[0] = BlackLineFollower_main_region_OnNode;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void blackLineFollower_enseq_main_region_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for region main region */
	blackLineFollower_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void blackLineFollower_enseq_main_region_linefollowing_r1_default(BlackLineFollower* handle)
{
	/* 'default' enter sequence for region r1 */
	blackLineFollower_react_main_region_linefollowing_r1__entry_Default(handle);
}

/* Default exit sequence for state linefollowing */
static void blackLineFollower_exseq_main_region_linefollowing(BlackLineFollower* handle)
{
	/* Default exit sequence for state linefollowing */
	blackLineFollower_exseq_main_region_linefollowing_r1(handle);
}

/* Default exit sequence for state right detects line */
static void blackLineFollower_exseq_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle)
{
	/* Default exit sequence for state right detects line */
	handle->stateConfVector[0] = BlackLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state center detects line */
static void blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle)
{
	/* Default exit sequence for state center detects line */
	handle->stateConfVector[0] = BlackLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state left detects line */
static void blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle)
{
	/* Default exit sequence for state left detects line */
	handle->stateConfVector[0] = BlackLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state none detects line */
static void blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle)
{
	/* Default exit sequence for state none detects line */
	handle->stateConfVector[0] = BlackLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OnNode */
static void blackLineFollower_exseq_main_region_OnNode(BlackLineFollower* handle)
{
	/* Default exit sequence for state OnNode */
	handle->stateConfVector[0] = BlackLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
static void blackLineFollower_exseq_main_region(BlackLineFollower* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of BlackLineFollower.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case BlackLineFollower_main_region_linefollowing_r1_right_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_right_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_center_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_left_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_none_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_OnNode :
		{
			blackLineFollower_exseq_main_region_OnNode(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void blackLineFollower_exseq_main_region_linefollowing_r1(BlackLineFollower* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of BlackLineFollower.main_region.linefollowing.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case BlackLineFollower_main_region_linefollowing_r1_right_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_right_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_center_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_center_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_left_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_left_detects_line(handle);
			break;
		}
		case BlackLineFollower_main_region_linefollowing_r1_none_detects_line :
		{
			blackLineFollower_exseq_main_region_linefollowing_r1_none_detects_line(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state right detects line. */
static void blackLineFollower_react_main_region_linefollowing_r1_right_detects_line(BlackLineFollower* handle)
{
	/* The reactions of state right detects line. */
	if (blackLineFollower_check_main_region_linefollowing_tr0_tr0(handle) == bool_true)
	{ 
		blackLineFollower_effect_main_region_linefollowing_tr0(handle);
	}  else
	{
		if (blackLineFollower_check_main_region_linefollowing_r1_right_detects_line_tr0_tr0(handle) == bool_true)
		{ 
			blackLineFollower_effect_main_region_linefollowing_r1_right_detects_line_tr0(handle);
		} 
	}
}

/* The reactions of state center detects line. */
static void blackLineFollower_react_main_region_linefollowing_r1_center_detects_line(BlackLineFollower* handle)
{
	/* The reactions of state center detects line. */
	if (blackLineFollower_check_main_region_linefollowing_tr0_tr0(handle) == bool_true)
	{ 
		blackLineFollower_effect_main_region_linefollowing_tr0(handle);
	}  else
	{
		if (blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr0_tr0(handle) == bool_true)
		{ 
			blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr0(handle);
		}  else
		{
			if (blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr1_tr1(handle) == bool_true)
			{ 
				blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr1(handle);
			}  else
			{
				if (blackLineFollower_check_main_region_linefollowing_r1_center_detects_line_tr2_tr2(handle) == bool_true)
				{ 
					blackLineFollower_effect_main_region_linefollowing_r1_center_detects_line_tr2(handle);
				} 
			}
		}
	}
}

/* The reactions of state left detects line. */
static void blackLineFollower_react_main_region_linefollowing_r1_left_detects_line(BlackLineFollower* handle)
{
	/* The reactions of state left detects line. */
	if (blackLineFollower_check_main_region_linefollowing_tr0_tr0(handle) == bool_true)
	{ 
		blackLineFollower_effect_main_region_linefollowing_tr0(handle);
	}  else
	{
		if (blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr0_tr0(handle) == bool_true)
		{ 
			blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr0(handle);
		}  else
		{
			if (blackLineFollower_check_main_region_linefollowing_r1_left_detects_line_tr1_tr1(handle) == bool_true)
			{ 
				blackLineFollower_effect_main_region_linefollowing_r1_left_detects_line_tr1(handle);
			} 
		}
	}
}

/* The reactions of state none detects line. */
static void blackLineFollower_react_main_region_linefollowing_r1_none_detects_line(BlackLineFollower* handle)
{
	/* The reactions of state none detects line. */
	if (blackLineFollower_check_main_region_linefollowing_tr0_tr0(handle) == bool_true)
	{ 
		blackLineFollower_effect_main_region_linefollowing_tr0(handle);
	}  else
	{
		if (blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr0_tr0(handle) == bool_true)
		{ 
			blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr0(handle);
		}  else
		{
			if (blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr1_tr1(handle) == bool_true)
			{ 
				blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr1(handle);
			}  else
			{
				if (blackLineFollower_check_main_region_linefollowing_r1_none_detects_line_tr2_tr2(handle) == bool_true)
				{ 
					blackLineFollower_effect_main_region_linefollowing_r1_none_detects_line_tr2(handle);
				} 
			}
		}
	}
}

/* The reactions of state OnNode. */
static void blackLineFollower_react_main_region_OnNode(BlackLineFollower* handle)
{
	/* The reactions of state OnNode. */
	if (blackLineFollower_check_main_region_OnNode_tr0_tr0(handle) == bool_true)
	{ 
		blackLineFollower_effect_main_region_OnNode_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void blackLineFollower_react_main_region__entry_Default(BlackLineFollower* handle)
{
	/* Default react sequence for initial entry  */
	blackLineFollower_enseq_main_region_linefollowing_default(handle);
}

/* Default react sequence for initial entry  */
static void blackLineFollower_react_main_region_linefollowing_r1__entry_Default(BlackLineFollower* handle)
{
	/* Default react sequence for initial entry  */
	blackLineFollower_enseq_main_region_linefollowing_r1_none_detects_line_default(handle);
}


