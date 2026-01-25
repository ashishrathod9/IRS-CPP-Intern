#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

  fork();
  printf("hello\n pid = %d \n ", getpid());

  return 0;
}

// fork()

//     This system call creates a new process by duplicating the calling process.

//     After fork(),
//     you now have two processes :

//     The parent process(original one)
//         .

//     The child process(newly created)
//         .

//     Both processes continue execution from the line after fork()
//         .
