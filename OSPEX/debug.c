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
	message m;
	m.m11_p1=NULL; /*pInfo*/
	//m.m11_i1=SELF;
	printf("1\n");
	_syscall(PM_PROC_NR, 69, &m);
	printf("2\n");
	return 0;
}