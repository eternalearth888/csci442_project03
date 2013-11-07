#include "kernel/system.h"
#include <minix/endpoint.h>
#include <minix/pi.h>

int do_get_q_f(struct proc *caller, message *m_ptr) {

	u64_t cpuFreq = cpu_get_freq(0);
	struct proc **queueheads;
	queueheads = get_cpu_var(0,run_q_head);
	struct qh *heads[NR_SCHED_QUEUES];

	for(int i=0; i<NR_SCHED_QUEUES; i++){
		if(queueheads[i]){
			strcpy(heads[i]->p_name, queueheads[i]->p_name);
			heads[i]->p_endpoint = queueheads[i]->p_endpoint;
		}
	}

	printf("P_name: %s, Endpoint: %d\n", heads[0]->p_name, heads[0]->p_endpoint);

	//pass back struct
	data_copy_vmcheck(caller, SELF, &heads, m_ptr->m11_e1, m_ptr->m11_p1, sizeof(heads)); 

	return(OK);
}