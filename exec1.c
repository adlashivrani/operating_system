#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
//	fork();
	printf("\nHello exec1....!--Pid: %d\n", getpid());
	char *str[] = {"Hello", "capgemini", NULL};
//	execve("./exec2", str, 0);
	printf("Back to exec1...");
	execve("./exec2", str, 0);
	return 0;
}
