#include <iostream>
#include <thread>
#include <mutex>

// one thread can lock same mutex multiple timed
//
using namespace std;

recursive_mutex m;
int buffer =0;

void recursion(char c,int loopFor){

  if(loopFor < 0){
    return ;
  }

  m.lock();
  cout << c << " " << buffer++ << endl;

  recursion(c, --loopFor);

  m.unlock();

  cout<< "unlock by " << c << endl;

}

int main(){
  thread t1(recursion, '0', 10);
  thread t2(recursion, '1', 10);
  t1.join();
  t2.join();

  return 0;
}
