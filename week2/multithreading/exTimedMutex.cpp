#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

timed_mutex m;
int myAmount =0;

void increment(int i){
  if(m.try_lock_for(chrono::seconds(2))){  //  wait until specified timeout duration has elapsed or the lock is acquired whichever comes first return true of success
    ++myAmount;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "thread" << i << "enterd" << endl;
    m.unlock();
  }else{

    cout << "thread" << i << "cudnt enterd" << endl;
  }
}
void increment2(int i){
  auto now = chrono::steady_clock::now();
  if(m.try_lock_until(now+chrono::seconds(2))){  //  wait until specified timeout duration has elapsed or the lock is acquired whichever comes first return true of success
    ++myAmount;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "thread" << i << "enterd" << endl;
    m.unlock();
  }else{

    cout << "thread" << i << "cudnt enterd" << endl;
  }
}

int main(){

  thread t1(increment,1);
  thread t2(increment,2);

  t1.join();
  t2.join();

  cout << myAmount << endl;
}
