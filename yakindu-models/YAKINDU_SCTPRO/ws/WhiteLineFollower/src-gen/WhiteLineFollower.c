
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "WhiteLineFollower.h"
#include "WhiteLineFollowerRequired.h"
/*! \file Implementation of the state machine 'WhiteLineFollower'
*/

/* prototypes of all internal functions */
static sc_boolean whiteLineFollower_check_White_Line_Follower_OnLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_OnLine_tr1_tr1(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr1_tr1(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_RightOfLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_RightOfLine_tr1_tr1(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_OutOfLine_tr0_tr0(const WhiteLineFollower* handle);
static sc_boolean whiteLineFollower_check_White_Line_Follower_OutOfLine_tr1_tr1(const WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_OnLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_OnLine_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr0(WhiteLineFollower* handle);
static void whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr1(WhiteLineFollower* handle);
static void whiteLineFollower_enact_White_Line_Follower_OnLine(WhiteLineFollower* handle);
static void whiteLineFollower_enact_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_enact_White_Line_Follower_RightOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_enact_White_Line_Follower_OutOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_White_Line_Follower_OnLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_White_Line_Follower_LeftOfLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_White_Line_Follower_RightOfLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_White_Line_Follower_OutOfLine_default(WhiteLineFollower* handle);
static void whiteLineFollower_enseq_White_Line_Follower_default(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_White_Line_Follower_OnLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_White_Line_Follower_RightOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_White_Line_Follower_OutOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_exseq_White_Line_Follower(WhiteLineFollower* handle);
static void whiteLineFollower_react_White_Line_Follower_OnLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_White_Line_Follower_RightOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_White_Line_Follower_OutOfLine(WhiteLineFollower* handle);
static void whiteLineFollower_react_White_Line_Follower__entry_Default(WhiteLineFollower* handle);
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
	handle->ifaceInput.left_sensor = 0;
	handle->ifaceInput.right_sensor = 0;
	handle->ifaceInput.center_sensor = 0;

}

void whiteLineFollower_enter(WhiteLineFollower* handle)
{
	/* Default enter sequence for statechart WhiteLineFollower */
	whiteLineFollower_enseq_White_Line_Follower_default(handle);
}

void whiteLineFollower_exit(WhiteLineFollower* handle)
{
	/* Default exit sequence for statechart WhiteLineFollower */
	whiteLineFollower_exseq_White_Line_Follower(handle);
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
		case WhiteLineFollower_White_Line_Follower_OnLine :
		{
			whiteLineFollower_react_White_Line_Follower_OnLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_LeftOfLine :
		{
			whiteLineFollower_react_White_Line_Follower_LeftOfLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_RightOfLine :
		{
			whiteLineFollower_react_White_Line_Follower_RightOfLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_OutOfLine :
		{
			whiteLineFollower_react_White_Line_Follower_OutOfLine(handle);
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
		case WhiteLineFollower_White_Line_Follower_OnLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_White_Line_Follower_OnLine
			);
			break;
		case WhiteLineFollower_White_Line_Follower_LeftOfLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_White_Line_Follower_LeftOfLine
			);
			break;
		case WhiteLineFollower_White_Line_Follower_RightOfLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_White_Line_Follower_RightOfLine
			);
			break;
		case WhiteLineFollower_White_Line_Follower_OutOfLine :
			result = (sc_boolean) (handle->stateConfVector[0] == WhiteLineFollower_White_Line_Follower_OutOfLine
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
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
sc_integer whiteLineFollowerIfaceInput_get_center_sensor(const WhiteLineFollower* handle)
{
	return handle->ifaceInput.center_sensor;
}
void whiteLineFollowerIfaceInput_set_center_sensor(WhiteLineFollower* handle, sc_integer value)
{
	handle->ifaceInput.center_sensor = value;
}

/* implementations of all internal functions */

static sc_boolean whiteLineFollower_check_White_Line_Follower_OnLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_OnLine_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 16 && handle->ifaceInput.right_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_RightOfLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_RightOfLine_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.center_sensor > 16 && handle->ifaceInput.left_sensor > 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_OutOfLine_tr0_tr0(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.left_sensor < 16) ? bool_true : bool_false;
}

static sc_boolean whiteLineFollower_check_White_Line_Follower_OutOfLine_tr1_tr1(const WhiteLineFollower* handle)
{
	return (handle->ifaceInput.right_sensor < 16) ? bool_true : bool_false;
}

static void whiteLineFollower_effect_White_Line_Follower_OnLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_OnLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_RightOfLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_OnLine_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_OnLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_LeftOfLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_LeftOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_OnLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_LeftOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_OutOfLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_RightOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_OnLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_RightOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_OutOfLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr0(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_OutOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_RightOfLine_default(handle);
}

static void whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr1(WhiteLineFollower* handle)
{
	whiteLineFollower_exseq_White_Line_Follower_OutOfLine(handle);
	whiteLineFollower_enseq_White_Line_Follower_LeftOfLine_default(handle);
}

/* Entry action for state 'OnLine'. */
static void whiteLineFollower_enact_White_Line_Follower_OnLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'OnLine'. */
	whiteLineFollowerIfaceInput_forward(handle);
}

/* Entry action for state 'LeftOfLine'. */
static void whiteLineFollower_enact_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'LeftOfLine'. */
	whiteLineFollowerIfaceInput_right(handle);
}

/* Entry action for state 'RightOfLine'. */
static void whiteLineFollower_enact_White_Line_Follower_RightOfLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'RightOfLine'. */
	whiteLineFollowerIfaceInput_left(handle);
}

/* Entry action for state 'OutOfLine'. */
static void whiteLineFollower_enact_White_Line_Follower_OutOfLine(WhiteLineFollower* handle)
{
	/* Entry action for state 'OutOfLine'. */
	whiteLineFollowerIfaceInput_stop(handle);
}

/* 'default' enter sequence for state OnLine */
static void whiteLineFollower_enseq_White_Line_Follower_OnLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state OnLine */
	whiteLineFollower_enact_White_Line_Follower_OnLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_White_Line_Follower_OnLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LeftOfLine */
static void whiteLineFollower_enseq_White_Line_Follower_LeftOfLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state LeftOfLine */
	whiteLineFollower_enact_White_Line_Follower_LeftOfLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_White_Line_Follower_LeftOfLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state RightOfLine */
static void whiteLineFollower_enseq_White_Line_Follower_RightOfLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state RightOfLine */
	whiteLineFollower_enact_White_Line_Follower_RightOfLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_White_Line_Follower_RightOfLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OutOfLine */
static void whiteLineFollower_enseq_White_Line_Follower_OutOfLine_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for state OutOfLine */
	whiteLineFollower_enact_White_Line_Follower_OutOfLine(handle);
	handle->stateConfVector[0] = WhiteLineFollower_White_Line_Follower_OutOfLine;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region White Line Follower */
static void whiteLineFollower_enseq_White_Line_Follower_default(WhiteLineFollower* handle)
{
	/* 'default' enter sequence for region White Line Follower */
	whiteLineFollower_react_White_Line_Follower__entry_Default(handle);
}

/* Default exit sequence for state OnLine */
static void whiteLineFollower_exseq_White_Line_Follower_OnLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state OnLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LeftOfLine */
static void whiteLineFollower_exseq_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state LeftOfLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state RightOfLine */
static void whiteLineFollower_exseq_White_Line_Follower_RightOfLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state RightOfLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OutOfLine */
static void whiteLineFollower_exseq_White_Line_Follower_OutOfLine(WhiteLineFollower* handle)
{
	/* Default exit sequence for state OutOfLine */
	handle->stateConfVector[0] = WhiteLineFollower_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region White Line Follower */
static void whiteLineFollower_exseq_White_Line_Follower(WhiteLineFollower* handle)
{
	/* Default exit sequence for region White Line Follower */
	/* Handle exit of all possible states (of WhiteLineFollower.White_Line_Follower) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case WhiteLineFollower_White_Line_Follower_OnLine :
		{
			whiteLineFollower_exseq_White_Line_Follower_OnLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_LeftOfLine :
		{
			whiteLineFollower_exseq_White_Line_Follower_LeftOfLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_RightOfLine :
		{
			whiteLineFollower_exseq_White_Line_Follower_RightOfLine(handle);
			break;
		}
		case WhiteLineFollower_White_Line_Follower_OutOfLine :
		{
			whiteLineFollower_exseq_White_Line_Follower_OutOfLine(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state OnLine. */
static void whiteLineFollower_react_White_Line_Follower_OnLine(WhiteLineFollower* handle)
{
	/* The reactions of state OnLine. */
	if (whiteLineFollower_check_White_Line_Follower_OnLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_White_Line_Follower_OnLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_White_Line_Follower_OnLine_tr1_tr1(handle) == bool_true)
		{ 
			whiteLineFollower_effect_White_Line_Follower_OnLine_tr1(handle);
		} 
	}
}

/* The reactions of state LeftOfLine. */
static void whiteLineFollower_react_White_Line_Follower_LeftOfLine(WhiteLineFollower* handle)
{
	/* The reactions of state LeftOfLine. */
	if (whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_White_Line_Follower_LeftOfLine_tr1_tr1(handle) == bool_true)
		{ 
			whiteLineFollower_effect_White_Line_Follower_LeftOfLine_tr1(handle);
		} 
	}
}

/* The reactions of state RightOfLine. */
static void whiteLineFollower_react_White_Line_Follower_RightOfLine(WhiteLineFollower* handle)
{
	/* The reactions of state RightOfLine. */
	if (whiteLineFollower_check_White_Line_Follower_RightOfLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_White_Line_Follower_RightOfLine_tr1_tr1(handle) == bool_true)
		{ 
			whiteLineFollower_effect_White_Line_Follower_RightOfLine_tr1(handle);
		} 
	}
}

/* The reactions of state OutOfLine. */
static void whiteLineFollower_react_White_Line_Follower_OutOfLine(WhiteLineFollower* handle)
{
	/* The reactions of state OutOfLine. */
	if (whiteLineFollower_check_White_Line_Follower_OutOfLine_tr0_tr0(handle) == bool_true)
	{ 
		whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr0(handle);
	}  else
	{
		if (whiteLineFollower_check_White_Line_Follower_OutOfLine_tr1_tr1(handle) == bool_true)
		{ 
			whiteLineFollower_effect_White_Line_Follower_OutOfLine_tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void whiteLineFollower_react_White_Line_Follower__entry_Default(WhiteLineFollower* handle)
{
	/* Default react sequence for initial entry  */
	whiteLineFollower_enseq_White_Line_Follower_OnLine_default(handle);
}


