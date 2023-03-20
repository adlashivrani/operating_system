#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define SIZE 50

int main()
{
	int fd;
	char buff[SIZE];
	fd = open("input.txt", O_RDONLY);
	if ( fd < 0) {
		printf("\nOPEN FAILED...\n");
		exit(1);
	}
	printf("fd opened :...%d", fd);
//	printf("\nenter input\n");
//	fgets(buff, SIZE, stdin);
//	write(fd, buff, SIZE);//writing to the fd
	read(fd, buff, SIZE); //reading from the fd
	printf("\nRead from fd: %s\n", buff);
	close(fd);
	return 0;
}

