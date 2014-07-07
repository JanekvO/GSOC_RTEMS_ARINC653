#define POK_CONFIG_NB_BLACKBOARDS 1
#define POK_NEEDS_BLACKBOARDS 1
#define POK_NEEDS_MIDDLEWARE 1
#define POK_NEEDS_ARINC653_BLACKBOARDS 1

#include <types.h>
#include <libc/stdio.h>
#include <arinc653/blackboard.h>
#include <arinc653/types.h>

BLACKBOARD_ID_TYPE blackboard;
RETURN_CODE_TYPE ret;

/*
 * Test for blackboard on POK. Doesn't compile just yet for some unknown reason.
 * 
 * Also: I am well aware that in the model.aadl it periodically calls this
 * function which is completely useless as that just continuously creates new
 * blackboards but it doesn't matter as I'm just trying to get this to work in
 * general disregarding the fact calling this multiple times is useless.
 */
void user_send ()
{	
	CREATE_BLACKBOARD(
		"blackboard without aadl generating blackboard arinc653 calls", 
		30, 
		&blackboard, 
		&ret);
	
	if(ret != 0)
	{
		printf("ret error after create blackboard: %d\n", (int)ret);
	}
}
