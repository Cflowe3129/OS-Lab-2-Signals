/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
bool handle = true;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handle = false;
}

int main(int argc, char * argv[])
{
  while(1) {
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    while(handle); //busy wait for signal to be delivered
    printf("Turing was Right\n");
    handle = true; //reset boolean value to reinstantiate the wait
  }
  
  return 0; //never reached
}