#include <stdio.h>     /* standard I/O functions                         */
#include <stdlib.h>    /* exit                                           */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */

/* first, define the Ctrl-C counter, initialize it with zero. */
int ctrl_c_count = 0;
int got_response = 0;
#define CTRL_C_THRESHOLD  5
//write a condition that terminates your program, if that condition isnt activated
//dont kill your program

/*time out signal handler*/
void catch_alrm(int sig_num)
{
  if(got_response == 0){
  printf("\n User is taking too long to respond. Exiting . . .\n");
  exit(0);
  }else{
  //do nothing
  }
}

/* the Ctrl-C signal handler */
void catch_int(int sig_num)
{
  /* increase count, and check if threshold was reached */
  ctrl_c_count++;
  if (ctrl_c_count >= CTRL_C_THRESHOLD) {
    char answer[30];

    /* prompt the user to tell us if to really
     * exit or not */
    printf("\nReally exit? [Y/n]: ");
    alarm(10);
    fflush(stdout);
    if (!fgets(answer, sizeof(answer), stdin)){
      got_response = 0;
    } else {
      got_response = 1;
      if (answer[0] == 'n' || answer[0] == 'N') {
        printf("\nContinuing\n");
        fflush(stdout);
        /*
         * Reset Ctrl-C counter
         */
        ctrl_c_count = 0;
      }
      else {
        printf("\nExiting...\n");
        fflush(stdout);
        exit(0);
      }
    }
  }
}

/* the Ctrl-Z signal handler */
void catch_tstp(int sig_num)
{
  /* print the current Ctrl-C counter */
  printf("\n\nSo far, '%d' Ctrl-C presses were counted\n\n", ctrl_c_count);
  fflush(stdout);
}

int main(int argc, char* argv[])
{
  struct sigaction sa;
  sigset_t mask_set;  /* used to set a signal masking set. */
  //assign sa.sa_handler 1 to each function, including the one you are supposed to write

  /* setup mask_set */
  sigfillset(&mask_set);
  sigdelset(&mask_set, SIGALRM);

  /* set signal handlers */
//six statements should be written here
//while and pause function to be written here\

  //assign catch_tstp to a sig handler and pair it with the SIGTSTP signal number
  sa.sa_handler = catch_tstp;
  sigaction(SIGTSTP, &sa, NULL);

  //assign catch_int to a signal handler and pair it with the SIGINT signal number
  sa.sa_handler = catch_int;
  sigaction(SIGINT, &sa, NULL);

  //setup alarm handler
  sa.sa_handler = catch_alrm;
  sigaction(SIGALRM, &sa, NULL);



  while(1) {
    //do something
    sleep(1);
  }


  return 0;
}
