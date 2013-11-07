#include "syslib.h"

int sys_get_q_f(message m, endpoint_t proc_ep)
{      
		m.m11_e1 = SELF;
        return(_kernel_call(SYS_GET_Q_F, &m));
}