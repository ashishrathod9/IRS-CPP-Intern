#include <iostream>

using namespace std;


class Demo {
  public:
    int x;
    int y;

    void display() const{
      // x++;
      cout<<x<<endl;
    }
}

void fun(const int &a, int &x){
  // a++;
}

int main(){

    const int a =10;

    int x =10;


    //  x++;

    // int *px = &x;

    const int *cpx = &x;

    // ++ *cpx;

    int const *cipx = &x;

    cipx= &a;

    int * const icpx = &x;

    // icpx = &a;

    const int * const cicpx = &x;

    // ++*cicpx;









}
