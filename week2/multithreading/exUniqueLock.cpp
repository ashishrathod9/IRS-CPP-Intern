// TOPIC: unique_lock In C++ (std::unique_lock<mutex> lock(m1))
// NOTES:

// 1. The class unique_lock is a mutex ownership wrapper.

// 2. It Allows:

//        a. Can Have Different Locking Strategies

//        b. time-constrained attempts at locking (try_lock_for, try_lock_until)

//        c. recursive locking

//        d. transfer of lock ownership (move not copy)

//        e. condition variables. (See this in coming videos)



// Locking Strategies

//    TYPE             EFFECTS(S)

// 1. defer_lock       do not acquire ownership of the mutex.

// 2. try_to_lock      try to acquire ownership of the mutex without blocking.

// 3. adopt_lock       assume the calling thread already has ownership of the mutex.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int buffer =0;

void task (const char* threadNumber, int loopFor){

  unique_lock<mutex> lock(m); // the class is a mutex ownership wrapper
  for(int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
}

void task2 (const char* threadNumber, int loopFor){

  unique_lock<mutex> lock(m,defer_lock); // not call lock no mutex m
  lock.lock();
  for(int i=0; i<loopFor; ++i){
    buffer++;
    cout << threadNumber << buffer << endl;
  }
}

int main(){
  thread t1(task,"t1",10);
  thread t2(task,"t2",10);
  t1.join();
  t2.join();
  return 0;
}
