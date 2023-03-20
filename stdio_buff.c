#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 	printf("Hello world\n ");
 	write(STDOUT_FILENO, "Ciao\n", 5);
//	printf("\nHolla");
//	printf("Hi\n");
 	if (fork() == -1)
		exit(1);
 	//	_exit(EXIT_SUCCESS);//for not flushing stdio buffers
 	/* Both child and parent continue execution here */
 //	exit(EXIT_SUCCESS);
}
