#include <stdio.h>
#include <stdlib.h>


int* createNumber() {
    int x = 42;  // Local variable on stack
    return &x;   // Returning address of local variable
}  // x goes out of scope here, memory is invalid


int main() {
  int *ptr = (int *)malloc(sizeof(int));
  *ptr = 100;
  printf("Value: %d\n", *ptr);  // Valid access

  free(ptr);  // Memory is freed

  // ptr is now a dangling pointer
  printf("Value after free: %d\n", *ptr);  // Undefined behavior!
  *ptr = 200;  // Writing to freed memory - dangerous!

  int *ptr2 = createNumber();
  printf("Value: %d\n", *ptr2);  // Undefined behavior!

  int *ptr3;
  {
        int x = 50;
        ptr3 = &x;  // ptr points to x
        printf("Inside block: %d\n", *ptr3);  // Valid
  }  // x goes out of scope here

  printf("Outside block: %d\n", *ptr3);  // Dangling pointer!



  return 0;
}
