#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("\nWe are in exec2...\n");
	printf("\nGet pid of exec2 = %d", getpid());
	return 0;
}
