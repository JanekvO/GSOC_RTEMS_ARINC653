GSOC_RTEMS_ARINC653
===================

Google Summer of Code project for RTEMS (http://www.rtems.org/). In this project 
we're trying to make available the ARINC653 calls on POK for RTEMS (only if
RTEMS is running virtualized on POK).

The folders in POK/* are basically code and/or changes concerning POK whilst 
the folder RTEMS/* is the folder with the changes on and for RTEMS.
The folder patches/* have patches that are about using arinc653 in RTEMS (using
POK's arinc653 implementation). The current status of the arinc653 calls is as
follows:

Arinc653 subset			Works?

partition:				yes
blackboard:				no
buffer:					no
error:					yes
event:					no
process:				yes
queueing:				no
sampling:				no
semaphore:				no
time: 					yes
