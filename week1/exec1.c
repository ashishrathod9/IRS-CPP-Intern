#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

  printf("pid of exec1.c is = %d\n", getpid());

  char *args[] = { "hello", "world", NULL};

  execv("./exec2", args);

  printf("back to exec1.c");

  return 0;
}

// execv("./exec2", args);
// Replaces the current process image with the new program(exec2).

//     That means :

//     The code of exec1.c is discarded.

//     The process continues execution as exec2.

//     Same PID is reused.

//     If execv() succeeds,
//     control never returns to exec1.c.The line printf("back to exec1.c");
// will not execute.
