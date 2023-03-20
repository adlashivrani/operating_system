#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void signal_handler(int sig);

int main()
{
	signal(SIGSEGV,signal_handler);
	char *str;
	while(1) {
		str = "hlo";
		*(str+1) = 'n';
		printf("\nInside main\n");	
		sleep(1);
	}
	return 0;
}

void signal_handler(int sig)
{
	//printf("Segmentation fault\n");
	printf("%p\n", signal_handler);
	sleep(1);
	//raise(SIGSEGV);
//	_exit(1);
}
