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
int ascending_order (const void* a, const void* b) {
  process* p1 = (process*)a;
  process* p2 = (process*)b;

  return p1->arrTime - p2->arrTime;
}

//comparer for descending order
int descending_order (const void* a, const void* b) {
  process* p1 = (process*)a;
  process* p2 = (process*)b;

  if(p1->priority == p2->priority){
    return p1->arrTime - p2->arrTime;
  }
  return p2->priority - p1->priority;
}

//parse the process.txt
void parse_file(char* a) {
  FILE *fp;
  //printf("parse_file");
  fp = fopen(a, "r");
  int pid;
  int at;
  int pri;
  if(fp){
    int pnum = 0;
    while(fscanf(fp, "%d %d %d", &pid, &at, &pri)!=EOF){
      process p1;
      p1.pid = pid;
      p1.arrTime = at;
      p1.priority = pri;
      Processes[pnum] = p1;
      pnum++;
    }
  }
}

int main(int argc, char **argv) {
  parse_file("process.txt");
  printf("Process.txt: \n");
  for(int i = 0; i < NUM_PROCS; i++) {
    process p = Processes[i];
    printf("pid: %d\t| arrival time: %d\t| priority: %d\n", p.pid, p.arrTime, p.priority);
  }
  
  printf("----------------------------------------\n");
  printf("By arrival time: \n");
  int (*ascending)(const void* a, const void* b) = ascending_order;
  qsort((void*)Processes, 7, sizeof(process), ascending);
  for(int i = 0; i < NUM_PROCS; i++) {
    process p = Processes[i];
    printf("pid: %d\t| arrival time: %d\t| priority: %d\n", p.pid, p.arrTime, p.priority);
  }

  printf("----------------------------------------\n");
  printf("By priority: \n");
  int (*descending)(const void* a, const void* b) = descending_order;
  qsort((void*)Processes, 7, sizeof(process), descending);
  for(int i = 0; i < NUM_PROCS; i++) {
    process p = Processes[i];
    printf("pid: %d\t| arrival time: %d\t| priority: %d\n", p.pid, p.arrTime, p.priority);
  }
  return 0;
}
