#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

long long bankBalance =0;

void addMoney(long long val){
  m.lock();
  bankBalance += val;
  m.unlock();x
}

int main(){
  thread t1(addMoney, 100);
  thread t2(addMoney, 200);
  t1.join();
  t2.join();

  std::cout << " bankBalance " <<bankBalance << std::endl;

  return 0;
}
