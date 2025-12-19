#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

ull findOdd(ull start, ull end){
    ull oddSum =0;
    cout<< this_thread::get_id()<<endl;
    for(ull i = start; i<=end; ++i){
      if(i & 1){
        oddSum += i;
      }
    }
    return oddSum;
  }

  int main(){

    ull start =0, end =190000000;

  cout<< this_thread::get_id()<<endl;
  cout<<"thread creadted if async" << endl;

  future<ull> oddSum = async(launch::async, findOdd, start, end);

  // future<ull> oddSum = async(launch::deferred, findOdd, start, end);// thread not creadted

  cout << "waiting " << endl;
  cout << "oddSum" << oddSum.get() << endl;

  cout<<"completed"<<endl;

  return 0;
}
