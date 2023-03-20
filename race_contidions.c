/* Parent and child race to write a message after fork()*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int numChildren, j;
 	pid_t childPid;
 	if (argc > 1 && strcmp(argv[1], "--help") == 0)
 		//usageErr("%s [num-children]\n", argv[0]);
		exit(1);
 	numChildren = ((argc > 1) ? argv[1] : 1);
 	setbuf(stdout, NULL); /* Make stdout unbuffered */
 	for (j = 0; j <10 /*numChildren*/; j++) {
 		switch (childPid = fork()) {
 			case -1:
 				exit(1);
 			case 0:
 				printf("%d child, child id: %d\n", j, getpid());
 			_exit(EXIT_SUCCESS);
 			default:
 				printf("%d parent, parent id: %d\n", j,getpid());
 				wait(NULL); /* Wait for child to terminate */
 				break;
 		}
 	}
 	exit(EXIT_SUCCESS);
	return 0;
}
