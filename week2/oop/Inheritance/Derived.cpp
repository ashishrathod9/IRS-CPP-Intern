#include <iostream>
using namespace std;

class Base{
  public:
    int a;
    void displayA(){
      cout<<"a : "<<a<<endl;
    }

    void fun(){
      cout<<"base fun"<<endl;
    }

    virtual void start(){
      cout<<"base start"<<endl;
    }
};

class Derived : public Base{
  public:
    int b;
    void displayB(){
      cout<<"b: "<<b<<endl;
    }
    void fun(){
      cout<<"Derived fun"<<endl;
    }

    void start(){
      cout<<"base start"<<endl;
    }
};


// class Parent final{

//      virtual  show () final{

//     }
// }
// class child:Parent{
//   void show (){

//   }
// }

int main(){
  Derived d;
  d.a=10;
  d.b=20;
  d.displayA();
  d.displayB();
  d.fun();

  Base *b = new Derived();
  b->fun();
  b->start();
  return 0;

}
