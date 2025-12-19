// return_type (*pointer_name)(parameter_types);
// int (*func_ptr)(int, int);


#include <stdio.h>

int add(int a, int b){
  return a + b;
}

int subtract(int a, int b){
  return a - b ;
}

int multiply(int a, int b){
  return a * b;
}

int divide(int a, int b){
  return b!=0 ? a / b : 0;
}


//callback function
void process_array(int arr[], int size,
void (*callback)(int)){

  for(int i =0; i< size; i++){
    callback(arr[i]);
  }
}

void print_square(int n){
  printf("%d squared = %d\n", n,n*n);
}

void print_double(int n){
  printf("%d doubled = %d\n", n, n * 2);
}

//fuction that returns a fuction pointer

int (*get_operation(char op))(int , int){
  if (op == '+'){
    return add;
  }
  else if (op == '-')
  {
    return subtract;
  }
  else if (op == '*')
  {
    return multiply;
  }
  else if (op == '/'){
    return divide;
  }
  else
    return NULL;
}



int main(){

  int (*operation)(int, int);  // function pointer declaration

  operation = &add;  // assigning address of add function to function pointer

  int result = operation(5,3); // calling function via pointer

  printf("result: %d\n", result);


  int (*calc)(int, int);
  int x=20, y =10;

  calc = &add;
  printf("Addition: %d\n", calc(x,y));

  calc = &subtract;
  printf("Subtraction: %d\n", calc(x,y));

  calc = &multiply;
  printf("Multiplication: %d\n", calc(x,y));

  calc = &divide;
  printf("Division: %d\n", calc(x,y));


  int (*operations[4])(int, int)
  = { add, subtract, multiply, divide}; // array of function pointers

  char *symbols[4] = {"+", "-", "*", "/"};


  for(int i=0; i<4; i++){
    printf("result %d  %s %d = %d \n", x, symbols[i], y, operations[i](x,y))
  }

  int nums[] = {1,2,3,4,5};
  int size = 5;

  process_array(nums, size, print_square);
  process_array(nums, size, print_double);


  operation = get_operation('+');
  printf(" %d\n", operation(10,5));



  return 0;
}
