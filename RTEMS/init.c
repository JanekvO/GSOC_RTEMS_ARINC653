/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define POK_NEEDS_ARINC653_PARTITION 1
#define POK_NEEDS_ARINC653_PROCESS 1

#include <rtems/test.h>

#include <bsp.h> /* for device driver prototypes */

#include <stdio.h>
#include <stdlib.h>
#include <arinc653/types.h>
#include <arinc653/partition.h>

/* forward declarations to avoid warnings */
rtems_task Init(rtems_task_argument argument);

const char rtems_test_name[] = "HELLO WORLD";

rtems_task Init(
  rtems_task_argument ignored
)
{
  //rtems_test_begin();
  //printf( "Hello World!\n" );
  //rtems_test_end();
  PARTITION_STATUS_TYPE partition_status;
  RETURN_CODE_TYPE 	ret;
  
  
  GET_PARTITION_STATUS(&partition_status, &ret);
  printf("ret after get partition:%d\n", ret);
  printf("OPERATING_MODE_TYPE:%d\n", partition_status.OPERATING_MODE);
  
  exit( 0 );
}


/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS            1
#define CONFIGURE_USE_DEVFS_AS_BASE_FILESYSTEM

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
