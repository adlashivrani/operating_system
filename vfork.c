#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static int idata = 10; /* Allocated in data segment */

int main(int argc, char *argv[])
{
 	int istack = 20; /* Allocated in stack segment */
 	pid_t childPid;
 	switch (childPid = vfork()) {
 		case -1:
 			exit(1);
 		case 0:
			sleep(3);//setting child to sleep
 			idata *= 3;
 			istack *= 3;
 			break;
 		default:
 			//sleep(0); /* Give child a chance to execute */
		//	wait(NULL);
 			break;
 	}
 	/* Both parent and child come here */
 	printf("\nPID=%ld %s idata=%d istack=%d\n", (long) getpid(), (childPid == 0) ? "(child) " : "(parent)", idata, istack);
 	exit(EXIT_SUCCESS);
}
