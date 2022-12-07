#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h>
#include<time.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
    
    
     int i;
     for(i=0; i< 2; i++)
     {
       pid = fork();
       if (pid == 0)
         {
           ChildProcess(i);
         } 
       else 
       if (pid < 0)
         {
           printf("Error in Fork\n");
         }
     }
     ParentProcess();      
          

  /*
     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
          */
}

void  ChildProcess(int kidId)
{
     int random_num, random_num2;
     int i;
  /*
     if (kidId == 0)
         {
           printf("In Child %d\n", kidId);
         } 
     else
     if (kidId == 1)
         {
           printf("In Child %d\n", kidId);
         } 
  */
  
     srand(getpid());
     random_num = (rand()%30) +1;
     for(i = 0; i <random_num ; i++)
     {
       printf("Child Pid: %d is going to sleep!\n",getpid());
       random_num2 = rand() % 10;
       //printf("Our Random # is: %d\n",random_num);
       sleep(random_num2 + 1);
       printf("Child Pid: is awake!\nWhere is My Parent %d ?\n",getppid());
     }
     
   
     //printf("Child Pid: %d is %d  %d going to sleep!\n",getpid(), kidId, i);
     //for (i = 1; i <= MAX_COUNT; i++)
       /*
         {
              printf("   This line is from child, value = %d\n", i);
         
         } */
        
     
     //printf("*** Child process is done ***\n");
     exit(0);
}


void  ParentProcess(void)
{
     int  i, pid, status;
     
     for (i = 0; i < 2; i++)
     {
       pid = wait(&status);
       printf("Child Pid: %d has completed\n", pid);
      // printf("This line is from parent, value = %d\n", i);
     }       
     //printf("*** Parent is done ***\n");
}