#**csci442 | fall 2013 | camp | project03**
##**TEAM**

- Maria Deslis @eternalearth888
	* HOURS:
		+ Intermediate One: 25.5
		+ Intermediate Two: 2
	- Mykala Miller @mymiller
	* HOURS:
		+ Intermediate One: 25.5
		+ Intermediate Two: 6
	- Austin Thompson @authompson
	* HOURS:
		+ Intermediate One: 25.5
		+ Intermediate Two: 6
	- Joseph Cirone @jcirone
	* HOURS:
		+ Intermediate One: 25.5
		+ Intermediate Two: 4

###Unusual/Interesting Features
N/A 

###Hardest part of the assignment
Retrieving the process table, specifically using the function sys_vircopy()

###Any additional comments regarding the assignment
First intermediate task took WAY too long; information & tutorials were insufficient

###How we modified Minix to retrieve a copy of the process table and how you implemented SPN scheduling
1. *PROCESS TABLE:*
	i. Implement a system call to the PM server
	ii. Implement a task call to the sched server
	iii. Call sys_getproctab()
	iv. Copy the returned process table to the user process with sys_vircopy() - This is where we stopped and turned in our work "as is"

2. *SPN SCHEDULING:*
	i. Get endpoints, other process information from proc1,...,proc10, and place it in the global sjf-struct array
	ii. Calculate burst time for the process that was preempted (if proc1,...,proc10)
	iii. Find which process has the shortest burst time
	iv. Dequeue and Enqueue the process with the shortest burst time (send endpoint of the process to the kernel with sys_qptab())

###Description of how team proved that SPN was implemented

###Results of Performance Analysis

####Pros/Cons Of Two Algorithms
