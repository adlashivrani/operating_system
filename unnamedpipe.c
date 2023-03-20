#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#define SIZE 128
int main()
{
        int filedes[2];
        int pid;
        FILE *fptr;
        FILE *fpptr;
        char cbuff[SIZE];
        char pbuff[SIZE];
        if (pipe(filedes) == -1) {
                printf("Error in Creating\n");
                exit(1);
        }
        pid = fork();
        if (pid == -1) {
                printf("Error Creating\n");
                exit(1);
        }
        if (pid == 0) {
                wait(NULL);
                close(filedes[1]);
                fptr = fopen("output.txt", "w+");
                if ((read(filedes[0], cbuff, SIZE)) == -1) {
                        printf("Error\n");
                        exit(1);
                }
                printf("%s", cbuff);
                fprintf(fptr, "%s", cbuff);
                close(filedes[0]);
                fclose(fptr);
        } else {
                close(filedes[0]);
                fpptr = fopen("input.txt", "r");
                fgets(pbuff, SIZE, fpptr);
                if (write (filedes[1], pbuff, SIZE) == -1) {
                        printf("Error\n");
                        exit(1);
                }
                close(filedes[1]);
                fclose(fpptr);
        }
	return 0;
}
