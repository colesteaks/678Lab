#include <stdlib.h>
#include <stdio.h>

#define NUM_PROCS           7


typedef struct {
  int pid; /*ID number given in processes.txt*/
  int arrTime; /*Arrival time given in processes.txt*/
  int priority; /*priority given in processes.txt*/
} process;

process Processes[NUM_PROCS];

//comparer for ascending order
int ascending_order (int a, int b) {
  return a-b;
}

//comparer for descending order
int descending_order (int a, int b) {
  return b-a;
}

//parse the process.txt
void parse_file(char* a) {
  FILE *fp;
  char buff[255];

  for(int i = 0; i < 21; i ++){

  }

  fp = fopen(a, "r");
  fgets(buff, 255, (FILE*)fp);
  int j = 0;
  for(int i = 0; i < 7; i++){
    process* p = new process();
    p->pid = buff[j];
    j++;
    p->arrTime = buff[j];
    j++;
    p->priority = buff[j];
    j++;
    &Processes[i] = p;
  }
}

int main(int argc, char **argv) {
  parse_file("process.txt");

  return 0;
}
