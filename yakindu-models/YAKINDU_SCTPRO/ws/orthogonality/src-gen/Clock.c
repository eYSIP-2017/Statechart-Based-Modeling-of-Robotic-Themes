
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "Clock.h"
/*! \file Implementation of the state machine 'clock'
*/

/* prototypes of all internal functions */
static sc_boolean clock_check_main_region_watch_x_zero_tr0_tr0(const Clock* handle);
static sc_boolean clock_check_main_region_watch_x_one_tr0_tr0(const Clock* handle);
static sc_boolean clock_check_main_region_watch_y_zero_tr0_tr0(const Clock* handle);
static sc_boolean clock_check_main_region_watch_y_one_tr0_tr0(const Clock* handle);
static void clock_effect_main_region_watch_x_zero_tr0(Clock* handle);
static void clock_effect_main_region_watch_x_one_tr0(Clock* handle);
static void clock_effect_main_region_watch_y_zero_tr0(Clock* handle);
static void clock_effect_main_region_watch_y_one_tr0(Clock* handle);
static void clock_enseq_main_region_watch_default(Clock* handle);
static void clock_enseq_main_region_watch_x_zero_default(Clock* handle);
static void clock_enseq_main_region_watch_x_one_default(Clock* handle);
static void clock_enseq_main_region_watch_y_zero_default(Clock* handle);
static void clock_enseq_main_region_watch_y_one_default(Clock* handle);
static void clock_enseq_main_region_default(Clock* handle);
static void clock_enseq_main_region_watch_x_default(Clock* handle);
static void clock_enseq_main_region_watch_y_default(Clock* handle);
static void clock_exseq_main_region_watch_x_zero(Clock* handle);
static void clock_exseq_main_region_watch_x_one(Clock* handle);
static void clock_exseq_main_region_watch_y_zero(Clock* handle);
static void clock_exseq_main_region_watch_y_one(Clock* handle);
static void clock_exseq_main_region(Clock* handle);
static void clock_exseq_main_region_watch_x(Clock* handle);
static void clock_exseq_main_region_watch_y(Clock* handle);
static void clock_react_main_region_watch_x_zero(Clock* handle);
static void clock_react_main_region_watch_x_one(Clock* handle);
static void clock_react_main_region_watch_y_zero(Clock* handle);
static void clock_react_main_region_watch_y_one(Clock* handle);
static void clock_react_main_region__entry_Default(Clock* handle);
static void clock_react_main_region_watch_x__entry_Default(Clock* handle);
static void clock_react_main_region_watch_y__entry_Default(Clock* handle);
static void clock_clearInEvents(Clock* handle);
static void clock_clearOutEvents(Clock* handle);


void clock_init(Clock* handle)
{
	sc_integer i;

	for (i = 0; i < CLOCK_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Clock_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	clock_clearInEvents(handle);
	clock_clearOutEvents(handle);


}

void clock_enter(Clock* handle)
{
	/* Default enter sequence for statechart clock */
	clock_enseq_main_region_default(handle);
}

void clock_exit(Clock* handle)
{
	/* Default exit sequence for statechart clock */
	clock_exseq_main_region(handle);
}

sc_boolean clock_isActive(const Clock* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Clock_last_state || handle->stateConfVector[1] != Clock_last_state)
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
sc_boolean clock_isFinal(const Clock* handle)
{
   return bool_false;
}

static void clock_clearInEvents(Clock* handle)
{
	handle->ifaceInput.a_raised = bool_false;
	handle->internal.b_raised = bool_false;
}

static void clock_clearOutEvents(Clock* handle)
{
}

void clock_runCycle(Clock* handle)
{
	
	clock_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < CLOCK_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Clock_main_region_watch_x_zero :
		{
			clock_react_main_region_watch_x_zero(handle);
			break;
		}
		case Clock_main_region_watch_x_one :
		{
			clock_react_main_region_watch_x_one(handle);
			break;
		}
		case Clock_main_region_watch_y_zero :
		{
			clock_react_main_region_watch_y_zero(handle);
			break;
		}
		case Clock_main_region_watch_y_one :
		{
			clock_react_main_region_watch_y_one(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clock_clearInEvents(handle);
}


sc_boolean clock_isStateActive(const Clock* handle, ClockStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Clock_main_region_watch :
			result = (sc_boolean) (handle->stateConfVector[0] >= Clock_main_region_watch
				&& handle->stateConfVector[0] <= Clock_main_region_watch_y_one);
			break;
		case Clock_main_region_watch_x_zero :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock_main_region_watch_x_zero
			);
			break;
		case Clock_main_region_watch_x_one :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock_main_region_watch_x_one
			);
			break;
		case Clock_main_region_watch_y_zero :
			result = (sc_boolean) (handle->stateConfVector[1] == Clock_main_region_watch_y_zero
			);
			break;
		case Clock_main_region_watch_y_one :
			result = (sc_boolean) (handle->stateConfVector[1] == Clock_main_region_watch_y_one
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void clockIfaceInput_raise_a(Clock* handle)
{
	handle->ifaceInput.a_raised = bool_true;
}



/* implementations of all internal functions */

static sc_boolean clock_check_main_region_watch_x_zero_tr0_tr0(const Clock* handle)
{
	return handle->ifaceInput.a_raised;
}

static sc_boolean clock_check_main_region_watch_x_one_tr0_tr0(const Clock* handle)
{
	return handle->ifaceInput.a_raised;
}

static sc_boolean clock_check_main_region_watch_y_zero_tr0_tr0(const Clock* handle)
{
	return handle->internal.b_raised;
}

static sc_boolean clock_check_main_region_watch_y_one_tr0_tr0(const Clock* handle)
{
	return handle->internal.b_raised;
}

static void clock_effect_main_region_watch_x_zero_tr0(Clock* handle)
{
	clock_exseq_main_region_watch_x_zero(handle);
	clock_enseq_main_region_watch_x_one_default(handle);
}

static void clock_effect_main_region_watch_x_one_tr0(Clock* handle)
{
	clock_exseq_main_region_watch_x_one(handle);
	handle->internal.b_raised = bool_true;
	clock_enseq_main_region_watch_x_zero_default(handle);
}

static void clock_effect_main_region_watch_y_zero_tr0(Clock* handle)
{
	clock_exseq_main_region_watch_y_zero(handle);
	clock_enseq_main_region_watch_y_one_default(handle);
}

static void clock_effect_main_region_watch_y_one_tr0(Clock* handle)
{
	clock_exseq_main_region_watch_y_one(handle);
	clock_enseq_main_region_watch_y_zero_default(handle);
}

/* 'default' enter sequence for state watch */
static void clock_enseq_main_region_watch_default(Clock* handle)
{
	/* 'default' enter sequence for state watch */
	clock_enseq_main_region_watch_x_default(handle);
	clock_enseq_main_region_watch_y_default(handle);
}

/* 'default' enter sequence for state zero */
static void clock_enseq_main_region_watch_x_zero_default(Clock* handle)
{
	/* 'default' enter sequence for state zero */
	handle->stateConfVector[0] = Clock_main_region_watch_x_zero;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state one */
static void clock_enseq_main_region_watch_x_one_default(Clock* handle)
{
	/* 'default' enter sequence for state one */
	handle->stateConfVector[0] = Clock_main_region_watch_x_one;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state zero */
static void clock_enseq_main_region_watch_y_zero_default(Clock* handle)
{
	/* 'default' enter sequence for state zero */
	handle->stateConfVector[1] = Clock_main_region_watch_y_zero;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state one */
static void clock_enseq_main_region_watch_y_one_default(Clock* handle)
{
	/* 'default' enter sequence for state one */
	handle->stateConfVector[1] = Clock_main_region_watch_y_one;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for region main region */
static void clock_enseq_main_region_default(Clock* handle)
{
	/* 'default' enter sequence for region main region */
	clock_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region x */
static void clock_enseq_main_region_watch_x_default(Clock* handle)
{
	/* 'default' enter sequence for region x */
	clock_react_main_region_watch_x__entry_Default(handle);
}

/* 'default' enter sequence for region y */
static void clock_enseq_main_region_watch_y_default(Clock* handle)
{
	/* 'default' enter sequence for region y */
	clock_react_main_region_watch_y__entry_Default(handle);
}

/* Default exit sequence for state zero */
static void clock_exseq_main_region_watch_x_zero(Clock* handle)
{
	/* Default exit sequence for state zero */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state one */
static void clock_exseq_main_region_watch_x_one(Clock* handle)
{
	/* Default exit sequence for state one */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state zero */
static void clock_exseq_main_region_watch_y_zero(Clock* handle)
{
	/* Default exit sequence for state zero */
	handle->stateConfVector[1] = Clock_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state one */
static void clock_exseq_main_region_watch_y_one(Clock* handle)
{
	/* Default exit sequence for state one */
	handle->stateConfVector[1] = Clock_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for region main region */
static void clock_exseq_main_region(Clock* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of clock.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Clock_main_region_watch_x_zero :
		{
			clock_exseq_main_region_watch_x_zero(handle);
			break;
		}
		case Clock_main_region_watch_x_one :
		{
			clock_exseq_main_region_watch_x_one(handle);
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of clock.main_region) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Clock_main_region_watch_y_zero :
		{
			clock_exseq_main_region_watch_y_zero(handle);
			break;
		}
		case Clock_main_region_watch_y_one :
		{
			clock_exseq_main_region_watch_y_one(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region x */
static void clock_exseq_main_region_watch_x(Clock* handle)
{
	/* Default exit sequence for region x */
	/* Handle exit of all possible states (of clock.main_region.watch.x) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Clock_main_region_watch_x_zero :
		{
			clock_exseq_main_region_watch_x_zero(handle);
			break;
		}
		case Clock_main_region_watch_x_one :
		{
			clock_exseq_main_region_watch_x_one(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region y */
static void clock_exseq_main_region_watch_y(Clock* handle)
{
	/* Default exit sequence for region y */
	/* Handle exit of all possible states (of clock.main_region.watch.y) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Clock_main_region_watch_y_zero :
		{
			clock_exseq_main_region_watch_y_zero(handle);
			break;
		}
		case Clock_main_region_watch_y_one :
		{
			clock_exseq_main_region_watch_y_one(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state zero. */
static void clock_react_main_region_watch_x_zero(Clock* handle)
{
	/* The reactions of state zero. */
	if (clock_check_main_region_watch_x_zero_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect_main_region_watch_x_zero_tr0(handle);
	} 
}

/* The reactions of state one. */
static void clock_react_main_region_watch_x_one(Clock* handle)
{
	/* The reactions of state one. */
	if (clock_check_main_region_watch_x_one_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect_main_region_watch_x_one_tr0(handle);
	} 
}

/* The reactions of state zero. */
static void clock_react_main_region_watch_y_zero(Clock* handle)
{
	/* The reactions of state zero. */
	if (clock_check_main_region_watch_y_zero_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect_main_region_watch_y_zero_tr0(handle);
	} 
}

/* The reactions of state one. */
static void clock_react_main_region_watch_y_one(Clock* handle)
{
	/* The reactions of state one. */
	if (clock_check_main_region_watch_y_one_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect_main_region_watch_y_one_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void clock_react_main_region__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq_main_region_watch_default(handle);
}

/* Default react sequence for initial entry  */
static void clock_react_main_region_watch_x__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq_main_region_watch_x_zero_default(handle);
}

/* Default react sequence for initial entry  */
static void clock_react_main_region_watch_y__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq_main_region_watch_y_zero_default(handle);
}


