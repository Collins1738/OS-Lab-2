#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <time.h>
#define   MAX_COUNT  2

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
	int status, i;
	int pid[MAX_COUNT];
	for(i = 0; i<MAX_COUNT; i++){
			pid[i] = fork();
			if (pid[i] == 0) 
					ChildProcess();
			else if(pid[i] == -1) printf("Error");
	}
	for (i = 0; i<MAX_COUNT; i++){
		wait(&status);
		printf("Child Pid: %d has completed!\n", pid[i]);
	}
		 
}

void  ChildProcess(void)
{
		int   i;
		srand(time(0));
		int randNum = rand()%30+1;
	
     for (i = 1; i <= randNum; i++){
			 pid_t childPid = getpid();
			 printf("Child Pid: %d is going to sleep! \n", childPid);
			 
			 int randTime = rand()%10+1;
			 sleep(randTime);
				 
			 pid_t parentPid = getppid();
			 printf("Child Pid: %d is awake! Where is my Parent: %d? \n", childPid, parentPid);
		}
		exit(0);
}
