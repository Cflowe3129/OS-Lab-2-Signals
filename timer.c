/* hello_timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
bool handleTimer = true;
int counter = 0;
void timerhandler(int signum)
{ //signal handler
  counter++;
  handleTimer = false;
}

void interruptHandler(int signum)
{ //signal handler
  printf("%d\n", counter);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGINT,interruptHandler); //register handler to handle SIGALRM
  while(1) {
    signal(SIGALRM,timerhandler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(handleTimer); //busy wait for signal to be delivered
    handleTimer = true; //reset boolean value to reinstantiate the wait
    printf("\n%d alarms occurred.\n", counter);
  }


  return 0; //never reached
}