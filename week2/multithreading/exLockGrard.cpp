#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int buffer =0;

void task(const char* threadNumber, int loopFor){
  m.lock();
  for(int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
  m.unlock();
}

void task2(const char* threadNumber, int loopFor){
  lock_guard<mutex> lock(m); // very light weight wrapper for owning mutex on scoped basis
  for(int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
}

int main(){
  thread t1(task2,"t0", 10);
  thread t2(task2,"t1", 10);
  t1.join();
  t2.join();
  return 0;
}
