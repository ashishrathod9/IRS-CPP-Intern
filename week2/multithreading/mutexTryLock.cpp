#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter =0;
mutex m;

void increaseTheCounterFor1000Time(){
  for(int i =0; i<100000; ++i){
    if(m.try_lock()){ // non blocking if cant lock than return false immediately
      ++counter;
      m.unlock();
    }
  }
}

int main(){
  thread t1(increaseTheCounterFor1000Time);
  thread t2(increaseTheCounterFor1000Time);

  t1.join();
  t2.join();

  cout<<counter<<endl;
}
