#include "ospex.h"
#include "glo.h"
#include "/usr/src/kernel/proc.h"

void OSSendPtab(void){
	// printf("OUR TASK CALL!\n");
	struct pi pInfo[HISTORY][NR_TASKS+NR_PROCS];
	struct proc table[NR_TASKS+NR_PROCS];
	int sample;

	if(sample && (snapshots < 50)) {	
		// table = malloc(sizeof(proct)*(NR_TASKS+NR_PROCS));
		//for 50 times

		sys_getproctab(&table);
		for(int i =0; i < NR_TASKS+NR_PROCS; i++) {
			strcpy(pInfo[snapshots][i].p_name, table[i].p_name);
			pInfo[snapshots][i].p_endpoint = table[i].p_endpoint;
			pInfo[snapshots][i].p_priority = table[i].p_priority;
			pInfo[snapshots][i].p_cpu_time_left = table[i].p_cpu_time_left;
			pInfo[snapshots][i].p_rts_flags = table[i].p_rts_flags;
			// pInfo[snapshots][i].queue_head = table[i].queue_head;

			pInfo[snapshots][i].p_nextready_endpoint = table[i].p_nextready->p_endpoint;
			
			pInfo[snapshots][i].p_times.enter_queue = table[i].p_accounting.enter_queue;
			pInfo[snapshots][i].p_times.time_in_queue = table[i].p_accounting.time_in_queue;
			pInfo[snapshots][i].p_times.dequeues = table[i].p_accounting.dequeues;
			pInfo[snapshots][i].p_times.ipc_sync = table[i].p_accounting.ipc_sync;
			pInfo[snapshots][i].p_times.ipc_async = table[i].p_accounting.ipc_async;
			pInfo[snapshots][i].p_times.preempted = table[i].p_accounting.preempted;

			strcpy(pInfo[snapshots][i].p_nextready, table[i].p_nextready->p_name);

			pInfo[snapshots][i].p_user_time = table[i].p_user_time;
			pInfo[snapshots][i].p_sys_time = table[i].p_sys_time;
			pInfo[snapshots][i].p_cycles = table[i].p_cycles;
		}
		snapshots++;
	}
	// printf("%p",m_in_glo.m11_p1);
	// printf("%s\n\n", table[0].p_name);
	// get info from table and put into a pi struct
	sys_vircopy(SELF, &pInfo, m_in_glo.m11_i1, m_in_glo.m11_p1, sizeof(pInfo));
}
