#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;


// Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section



// Mutex: Mutual Exclusion



// RACE CONDITION:

// 0. Race condition is a situation where two or more threads/process happened to change a common data at the same time.

// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.



// MUTEX:

// 0. Mutex is used to avoid race condition.

// 1. We use lock() , unlock() on mutex to avoid race condition.


int myAmount =0;

void addMoney(){
  ++myAmount; // critical ration
}

mutex m;
void addMoney2(){
  m.lock();
  ++myAmount;
  m.unlock();
}

int main(){

  // thread t1(addMoney);
  // thread t2(addMoney);

  // t1.join();
  // t2.join();

  thread t1(addMoney2);
  thread t2(addMoney2);

  t1.join();
  t2.join();

  cout<< myAmount << endl;

  return 0;
}
