#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pd = fork();
	if (pd < 0) {
		exit(1);
	} else if ( pd == 0) {
		sleep(30);
		printf("child: %d\n", getpid());
		printf("parent ppid: %d\n", getppid());
		//exit(1);
	} else {
		//sleep(20);
		printf("parent: %d\n", getpid());
		exit(1);
	}
	return 0;
}
