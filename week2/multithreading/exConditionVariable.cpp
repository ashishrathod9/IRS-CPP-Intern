// TOPIC: Condition Variable In C++ Threading
// NOTES:

// 1. Condition variables allow us to synchronize threads via notifications.

//    a. notify_one();

//    b. notify_all();

// 2. You need mutex to use condition variable

// 3. Condition variable is used to synchronize two or more threads.

// 4. Best use case of condition variable is Producer/Consumer problem.

// 5. Condition variables can be used for two purposes:

//     a. Notify other threads

//     b. Wait for some condition




#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

condition_variable cv;
mutex m;
long balance =0;

void addMoney(int money){
  lock_guard<mutex> lg(m);
  balance += money;
  cout << "amount added " << balance << endl;
  cv.notify_one();
}

void withdrawMoney(int money){
  unique_lock<mutex> ul(m);
  cv.wait(ul, []{ return (balance !=0) ? true : false;});
  if(balance >= money){
    balance -= money;
    cout << "deducted :" << money << endl;
  }else{
    cout << "cant be deducted" << money << endl;
  }
  cout << "current balance :" << balance << endl;
}

int main(){
  thread t1 (withdrawMoney, 500);
  this_thread::sleep_for(chrono::seconds(2));
  thread t2 (addMoney, 500);
  t1.join();
  t2.join();
}
