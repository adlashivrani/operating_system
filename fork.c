#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t cd;
	cd  = fork();
	if ( cd < 0) {
		printf("Fork failed..\n");
	} else if ( cd == 0) { //child process created
		printf("\nIn child process...%d\n", getpid());
	} else { //parent process
		wait(NULL);
		printf("\nIn parent process...%d\n", getpid());
	}
	return 0;
}

	
