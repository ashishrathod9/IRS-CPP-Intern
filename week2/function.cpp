#include <iostream>
using namespace std;

int add(int a = 0, int b){
  return a +b;
}

float add(float a = 0.0, float b){
  return a+b;
}

template<class T>
T add(T a, T b){
  return a + b;
}


int swap(int a, int b){
  int temp = a;
  a =b;
  b =temp;
  return 0;
}//pass by value

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}//pass by reference


void displayCounter(){
  static int counter =0;
  counter++;
  cout<<counter<<endl;
}

int sum(int n, ...){
  va_list list;
  va_start(list,n);

  int s =0;
  for(int i=0; i<n; i++){
    s += va_arg(list, int);
  }
  va_end(list);
  return s;
}



int main(){
  cout<<add(5,10)<<endl;
  cout<<add(5.5f,10.5f)<<endl;
  cout<<add<double>(5.5,10.5)<<endl;

  int x =5, y=10;
  cout<<"Before swap: x="<<x<<" y="<<y<<endl;
  swap(&x,&y);
  cout<<"After swap: x="<<x<<" y="<<y<<endl;

  displayCounter();
  displayCounter();
  displayCounter();

  [](){
    cout<<"helllo";
  }();

  auto f = [](){
    cout<<"helllo";
  }();

  f();


  [](int x, int y){
    cout<<"helllo"<< x +y << endl;
  }(10,20);


  int s = [](int x, int y)->int{ return x+y};

  int a =10;
  int b =10;

  [a,b](){cout<<++a<<}++b<<endl;}();
  [&a,&b](){cout<<++a<<}++b<<endl;}();
  [&](){cout<<++a<<}++b<<endl;}();



  return 0;

}
