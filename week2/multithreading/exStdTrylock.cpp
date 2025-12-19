#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

//std::try_lock try to lock multiple mutex object at the same Time
//on success return -1
//else return 0-base mutex index number which not block
//if it fails to lock the mutex than it will release all the mutex it locked befor

using namespace std;
using namespace std::chrono;

int x=0, y=0;
mutex m1 ,m2;

void doSomeWorkForSeconds(int seconds){
  this_thread::sleep_for(chrono::seconds(seconds));
}

void incrementXY(int & XorY, mutex & m,const char* desc){
  for(int i=0; i<5; i++){
    m.lock();
    ++XorY;
    cout << desc << XorY << endl;
    m.unlock();
    doSomeWorkForSeconds(1);
  }
}

void consumeXY(){
  int useCount =5;
  int XplusY =0;
  while(1){
    int lockResult = try_lock(m1,m2);
    if(lockResult == -1){

      if(x!=0 && y!=0){
        --useCount;
        XplusY +=x+y;
        x=0;
        y=0;
        cout << "XplusY" << XplusY <<endl;
      }
      m1.unlock();
      m2.unlock();
      if(useCount == 0) break;
    }
  }
}
int main(){

  thread t1(incrementXY, ref(x), ref(m1),"x ");
  thread t2(incrementXY, ref(y), ref(m2),"y ");
  thread t3(consumeXY);

  t1.join();
  t2.join();
  t3.join();

  return 0;

}
