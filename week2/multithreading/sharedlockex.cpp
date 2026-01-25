#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
using namespace std;

class ThreadSafeCounter
{
private:
  mutable std::shared_mutex mtx;
  int value_ = 0;

public:
  int read() const
  {
    std::shared_lock<std::shared_mutex> lock(mtx);
    return value_;
  }

  void increment()
  {
    std::unique_lock<std::shared_mutex> lock(mtx);
    ++value_;
  }

  void add(int val)
  {
    std::unique_lock<std::shared_mutex> lock(mtx);
    value_ += val;
  }
};

int main()
{
  ThreadSafeCounter counter;

  vector<thread> readers;
  for (int i = 0; i < 3; ++i)
  {
    readers.emplace_back([&counter, i]()
                         {
            for (int j = 0; j < 3; ++j) {
                int value = counter.read();
                cout << "Reader " << i
                     << " (Thread ID: " << this_thread::get_id()
                     << ") read: " << value << "\n\n";
                this_thread::sleep_for(chrono::milliseconds(100));
            } });
  }

  vector<thread> writers;
  for (int i = 0; i < 2; ++i)
  {
    writers.emplace_back([&counter, i]()
                         {
            for (int j = 0; j < 3; ++j) {
                counter.increment();
                cout << "Writer " << i
                     << " (Thread ID: " << this_thread::get_id()
                     << ") incremented\n\n";
                this_thread::sleep_for(chrono::milliseconds(150));
            } });
  }

  for (auto &t : readers)
    t.join();
  for (auto &t : writers)
    t.join();

  cout << "Final value: " << counter.read() << "\n";
}
