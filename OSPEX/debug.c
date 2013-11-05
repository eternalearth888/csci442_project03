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
	m.m11_p1=(char*)&pInfo; /*pInfo*/
	m.m11_i1=SELF;
	_syscall(PM_PROC_NR, 69, &m);
	return 0;
}