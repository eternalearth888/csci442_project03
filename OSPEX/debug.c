#include <sys/svrctl.h>
#include <sys/types.h>
#include <ctype.h>
#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minix/com.h"
#include "student.h"

int main(int argc, const char* argv[]) {
	struct pi pInfo[HISTORY][ALL_PROCS];
	message m;
	// printf("%s\n", &pInfo );
	m.m11_p1=&pInfo; /*pInfo*/
	printf("Debug:\n");
	printf("Pointer: %p, Integer: %d\n", &pInfo, SELF);
	m.m11_e1=SELF;
	// strcpy(pInfo[0][0].p_name, "Garbage");
	_syscall(PM_PROC_NR, 69, &m);

	// printf("asdf%s", pInfo[0][0].p_name);
	printf("%d", pInfo[0][0].p_endpoint);
	return 0;
}