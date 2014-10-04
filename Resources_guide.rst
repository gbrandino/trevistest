.. contents:: Table of Contents

HW Tech-spec
------------

For this course two computer facilities are made available: the ICTP HPC system named Argo, and the CNR/IOM system called Elcid.
Both facilities are based on "fair sharing" among users. However, for this course dedicated resources have been reserved.
TORQUE Resource Manager on top of the Maui cluster scheduler, are used for managing the resources available and manage users job submission efficiently.  

Argo
----

The Argo HPC system is composed by two login nodes and a series of hundreds of compute nodes equipped with different CPU architectures of the Intel Processor Family. 
The overall number amounts to approximately 2600 cores. On Argo, two different queues are dedicated to this course based on different CPU systems.
The mhpc queue is configured among 4 nodes, each nodes has two quad-cores Intel Xeon sockets while the gpu queue is configured on a single node system with two six-cores Intel Xeon sockets and two NVIDIA TESLA K20.

More information about the ICTP Argo system can be obtained from the official documentation at http://argo.ictp.it/documentation/specification

Elcid
-----
The CNR/IOM Elcid system is composed of a login node and 8 nodes equipped with four sockets AMD Opteron.
An mhpc queue was configured for this course with two of this nodes reserved for the course journey.

More information about the CNR/IOM Elcid system can be obtained from the official documentation at http://doc.escience-lab.org/elcid/ 


Access
------
 
Access is provided via  ssh, and the machine can be reached with the following commands:

Argo: 

 - ssh *{your-ictp-username}@argo.ictp.it*

Elcid: 

 - Logon SISSA-VPN network (see http://www.itcs.sissa.it/services/network/vpnclient to configure it)
 - ssh *{your-sissa-username}@elcid.hpc.sissa.it*


Available queues
---------------

Argo: 

 - *mhpc*  : 4 computing nodes
 - *gpu* : 1 computing node with 2 NVIDIA TESLA K20

Elcid: 

 - *mhpc* : 2 computing nodes


Submitting a job 
----------------

For both the system, the resource manager is Torque.
The typical script looks like
::


	#!/bin/bash
	#PBS -N MyRun 
	#PBS -l walltime=00:45:00
	#PBS -l nodes=1:ppn=16
	#PBS -q mhpc 

	module purge
	module load mkl/intel

	./my_program.x > output.txt 


- *#!/bin/bash* as usual, specifies the interpreter
- *#PBS -N MyRun* gives the possibilty to specify a name for the job
- *#PBS -l walltime=00:45:00* the maximum time the job can run, in hh:mm:SS format
- *#PBS -l nodes=1:ppn=16* tell to use 1 node. The number of cores reserved on a given must also be specified. Only the entire node can be allocated.
- *#PBS -q mhpc* specifies in which queue the job should be submitted

- *$PBS_O_WORKDIR*   indicates the  working  

- *module purge* and *module load mkl/intel*  prepare the run-time environment (see below)

- *./my_program.x > output.txt* calls the executable and dump the stdout (to redirect the stderr to stdout add *2>&1*)

Appendix: Modulefiles
---------------------

The module command will let you load and unload the environment needed to run specific applications or use specific libraries. It is especially useful when you need to have different versions of the same software/library or the same software/library compiled against different compilers.


Module HOWTO
-----------

The syntax of the module command is the following:

- *module* <subcommand> [<arguments>]

<subcommand> may or may not require one or more <arguments>

Those requiring arguments are **bold**

A partial list of available subcommands follows:

- list : to list the currently loaded modules
- avail : to list all the available modules
- load : to load one or more modules
- **unload** : to unload one or more modules
- **purge** : to unload all the currently loaded modules
- **show** : print on the standard output all the steps performed by the module command
A detailed list of all subcommands is shown by running the command *module help*
<arguments> are usually shown


