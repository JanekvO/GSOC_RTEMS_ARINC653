#include <types.h>
#include <libc/stdio.h>
#include <arinc653/partition.h>
#include <arinc653/types.h>

RETURN_CODE_TYPE ret;

/*
 * Test for arinc653 partition calls on POK. Does compile and works fine.
 */
void user_send ()
{
  PARTITION_STATUS_TYPE partition_status;
  RETURN_CODE_TYPE 	ret;
  
  GET_PARTITION_STATUS(&partition_status, &ret);
  printf("ret after get_partition_status:%d\n", ret);
  printf("OPERATING_MODE_TYPE:%d\n", partition_status.OPERATING_MODE); //returns 3 i.e. operating mode = NORMAL
}
