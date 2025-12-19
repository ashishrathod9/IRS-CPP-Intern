#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <deque>

using namespace std;

mutex m;
condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

bool done = false;

void producer(int val) {
    while (val) {
        unique_lock<mutex> locker(m);
        cond.wait(locker, [](){ return buffer.size() < maxBufferSize; });

        buffer.push_back(val);
        cout << "produced: " << val << endl;
        val--;

        locker.unlock();
        done = true;
        cond.notify_one();
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> locker(m);
        cond.wait(locker, [] { return buffer.size() > 0 || done; });

        if (buffer.size() == 0 && done) {
            break;
        }

        int val = buffer.back();
        buffer.pop_back();
        cout << "consumed: " << val << endl;

        locker.unlock();
        cond.notify_one();
    }
}

int main() {
    thread t1(producer, 100);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
