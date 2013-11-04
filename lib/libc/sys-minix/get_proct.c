#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>

#include <unistd.h>

#ifdef __weak_alias
__weak_alias(get_proct, _get_proct)
#endif

void get_proct(char* table)
{
	message m;
	m.m11_p1=table;

	_syscall(PM,69,&m);
}