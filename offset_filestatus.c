#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd, flags;
	char template[] = "/tmp/testXXXXXX";
 	setbuf(stdout, NULL); /* Disable buffering of stdout *///creates a new buffer
 	fd = mkstemp(template);
 	if (fd == -1)
 		exit(1);
 	printf("File offset before fork(): %lld\n",(long long) lseek(fd, 0, SEEK_CUR));
 	flags = fcntl(fd, F_GETFL);
 	if (flags == -1)
 		exit(1);
 	printf("O_APPEND flag before fork() is: %s\n",(flags & O_APPEND) ? "on" : "off");
 	switch (fork()) {
 		case -1:
 			exit(1);
 		case 0: /* Child: change file offset and status flags */
 			if (lseek(fd, 1000, SEEK_SET) == -1)
 				exit(1);
 			flags = fcntl(fd, F_GETFL); /* Fetch current flags */
 			if (flags == -1)
 				exit(1);
 			flags |= O_APPEND; /* Turn O_APPEND on */
 			if (fcntl(fd, F_SETFL, flags) == -1)
 				exit(1);
			_exit(EXIT_SUCCESS);
 		default: /* Parent: can see file changes made by child */
 			if (wait(NULL) == -1)
				exit(1); /* Wait for child exit */
			//exit(0);
			//exit(EXIT_FAILURE);
			printf("Child has exited\n");
			printf("File offset in parent: %lld\n",(long long) lseek(fd, 0, SEEK_CUR));
			flags = fcntl(fd, F_GETFL);
			if (flags == -1)
				exit(1);
			printf("O_APPEND flag in parent is: %s\n",(flags & O_APPEND) ? "on" : "off");
 			exit(EXIT_SUCCESS);
 	}
}
