#include "ospex.h"
#include "glo.h"
#include "/usr/src/kernel/proc.h"
#include "/usr/src/include/minix/syslib.h"
#include </usr/src/lib/libsys/sys_get_q_f.c>


struct pi pInfo[50][NR_TASKS+NR_PROCS];
struct qh qH[NR_SCHED_QUEUES];
int sample;
int snapshots;
int srcAddr;

void OSSendPtab(void){
	// printf("OUR TASK CALL!\n");
	struct proc table[NR_TASKS+NR_PROCS];

	if(sample) {
		if(snapshots < 50) {	
			// table = malloc(sizeof(proct)*(NR_TASKS+NR_PROCS));
			//for 50 times
			sys_getproctab(&table);

			for(int i=0; i < NR_TASKS+NR_PROCS; i++) {
				if(table[i].p_name) {
					strcpy(pInfo[snapshots][i].p_name, table[i].p_name);
					pInfo[snapshots][i].p_endpoint = table[i].p_endpoint;
					pInfo[snapshots][i].p_priority = table[i].p_priority;
					pInfo[snapshots][i].p_cpu_time_left = table[i].p_cpu_time_left;
					pInfo[snapshots][i].p_rts_flags = table[i].p_rts_flags;
					// pInfo[snapshots][i].queue_head = table[i].queue_head;
					if(table[i].p_nextready) {
						pInfo[snapshots][i].p_nextready_endpoint = table[i].p_endpoint;
						strcpy(pInfo[snapshots][i].p_nextready, table[i].p_name);
					}
					else {
						strcpy(pInfo[snapshots][i].p_nextready, NOPROC);
						pInfo[snapshots][i].p_nextready_endpoint = -1;
					}

					pInfo[snapshots][i].p_times.enter_queue = table[i].p_accounting.enter_queue;
					pInfo[snapshots][i].p_times.time_in_queue = table[i].p_accounting.time_in_queue;
					pInfo[snapshots][i].p_times.dequeues = table[i].p_accounting.dequeues;
					pInfo[snapshots][i].p_times.ipc_sync = table[i].p_accounting.ipc_sync;
					pInfo[snapshots][i].p_times.ipc_async = table[i].p_accounting.ipc_async;
					pInfo[snapshots][i].p_times.preempted = table[i].p_accounting.preempted;

					pInfo[snapshots][i].p_user_time = table[i].p_user_time;
					pInfo[snapshots][i].p_sys_time = table[i].p_sys_time;
					pInfo[snapshots][i].p_cycles = table[i].p_cycles;
				}
				else {
					printf("There is a null table value\n");
				}
			}
			snapshots++;
			// printf("%d; %p", m_in_glo.m11_i1, m_in_glo.m11_p1);
		}
		else {
			printf("First: %d, Second: %p, Third: %d, Fourth: %p, Fifth: %d", SELF, &pInfo, srcAddr, m_in_glo.m11_p1, sizeof(pInfo) );
			sys_vircopy(SELF, (vir_bytes) pInfo, srcAddr, (vir_bytes) m_in_glo.m11_p1, sizeof(pInfo));
			sample = 0;
			snapshots = 0;
		}
		message m_k;
		m_k.m11_p1 = (char*) &qH;
		sys_get_q_f(m_k, SELF);
	}	
}
