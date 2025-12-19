#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void run (int count){
  while(count --> 0){

    cout << "hello" << endl;
    this_thread::sleep_for(chrono::seconds(3));
  }

}

int main() {
    thread t1(run, 10);

    cout << "main" << endl;

    if (t1.joinable()) {
      t1.join();
    }
    t1.detach();

    cout << "main after" << endl;
    return 0;
}
