#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256

#define BASH_EXEC  "/bin/bash"
#define FIND_EXEC  "/bin/find"
#define XARGS_EXEC "/usr/bin/xargs"
#define GREP_EXEC  "/bin/grep"
#define SORT_EXEC  "/bin/sort"
#define HEAD_EXEC  "/usr/bin/head"

int main(int argc, char *argv[])
{
  int status;
  pid_t pid_1, pid_2, pid_3, pid_4;

  if (argc != 4) {
    printf("usage: finder DIR STR NUM_FILES\n");
    exit(0);
  }
//create three pipes in between the three processes.
//must close other ends of pipes or else program wont work
//dup2 actually connects the two processes
//define one array with 6 arguments as a file descriptor for pipe
//assign each end of the pipe that you need to input or output a string
//must close pipe within the process
  int pipefd[2];
  int pipefd2[2];
  int pipefd3[2];
  
  //initialize first pipe
  if(pipe(pipefd) == -1){
   perror("pipe");
	exit(EXIT_FAILURE); 
  }
  if(pipe(pipefd2) == -1){
   perror("pipe");
	exit(EXIT_FAILURE); 
  }
  if(pipe(pipefd3) == -1){
   perror("pipe");
	exit(EXIT_FAILURE); 
  }
 
  pid_1 = fork();
  if(pid_1 == -1){
	perror("fork");
	exit(EXIT_FAILURE);  
  }
  if (pid_1 == 0) {
    /* First Child */
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -name \'*\'.[ch]", FIND_EXEC, argv[1]);
    
	 //duplicate the stdout fileno file descriptor into the write end of the first pipe    
    dup2(pipefd[1], STDOUT_FILENO);
    
    close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[1]);
    close(pipefd2[0]);
    close(pipefd3[0]);
    close(pipefd3[1]);
    if((execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0))<0) {
		fprintf(stderr, "\nError executing find. ERROR#%d\n", errno);    
    }  
    
    exit(0);
  }

  pid_2 = fork();
  if(pid_2 == -1){
	perror("fork");
	exit(EXIT_FAILURE);  
  }
  if (pid_2 == 0) {
    /* Second Child */

    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    
	 dup2(pipefd[0], STDIN_FILENO);    
   
    
    sprintf(cmdbuf, "%s %s -c %s", XARGS_EXEC, GREP_EXEC, argv[2]);
    //printf("\nin the second process!!!\n");
    //printf(cmdbuf);
    dup2(pipefd2[1], STDOUT_FILENO);

    
    close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[1]);
    close(pipefd2[0]);
    close(pipefd3[0]);
    close(pipefd3[1]);
    
    if((execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0))<0) {
		fprintf(stderr, "\nError executing grep. ERROR#%d\n", errno);    
    }
    
    
    exit(0);
  }

  pid_3 = fork();
  if(pid_3 == -1){
	perror("fork");
	exit(EXIT_FAILURE);  
  }
  if (pid_3 == 0) {
    
    /* Third Child */
    
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    
	 dup2(pipefd2[0], STDIN_FILENO);    
    close(pipefd2[0]);
    
    sprintf(cmdbuf, "%s -t : +1.0 -2.0 --numeric --reverse", SORT_EXEC);
    
    //printf("\nin the third process!!!\n");
    
    dup2(pipefd3[1], STDOUT_FILENO);
    close(pipefd3[1]);
    
	 close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[1]);
    //close(pipefd2[0]);
    close(pipefd3[0]);
    //close(pipefd3[1]);    
    
    if((execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0))<0) {
		fprintf(stderr, "\nError executing grep. ERROR#%d\n", errno);    
    }   
    
    exit(0);
  }

  pid_4 = fork();
  if(pid_4 == -1){
	perror("fork");
	exit(EXIT_FAILURE);  
  }
  if (pid_4 == 0) {
    /* Fourth Child */    
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    
	 dup2(pipefd3[0], STDIN_FILENO);    
    close(pipefd3[0]);
    
    sprintf(cmdbuf, "%s --lines=%s", HEAD_EXEC, argv[3]);
    //printf("\nin the fourth process!!!\n");
    
	 close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);
    close(pipefd3[1]);
    close(pipefd3[0]);    
    
    if((execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0))<0) {
		fprintf(stderr, "\nError executing grep. ERROR#%d\n", errno);    
    }
    
    
    exit(0);
  }
  
    close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);
    close(pipefd3[1]);
    close(pipefd3[0]);

  if ((waitpid(pid_1, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_2, &status, 0)) == -1) {
    fprintf(stderr, "Process 2 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_3, &status, 0)) == -1) {
    fprintf(stderr, "Process 3 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_4, &status, 0)) == -1) {
    fprintf(stderr, "Process 4 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }

  return 0;
}

//int execl(.... char*0)
