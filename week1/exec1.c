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
