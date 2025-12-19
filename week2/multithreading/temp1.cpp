#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

mutex m;

void findEven(ull start, ull end) {
    ull localSum = 0;
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0) {
            localSum += i;
        }
    }
    lock_guard<mutex> lock(m);
    evenSum += localSum;
}

void findOdd(ull start, ull end) {
    ull localSum = 0;
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 1) {
            localSum += i;
        }
    }
    lock_guard<mutex> lock(m);
    oddSum += localSum;
}

int main() {
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Odd Sum: " << oddSum << endl;
    cout << "Even Sum: " << evenSum << endl;
    cout << "Time (seconds): " << duration.count() / 1'000'000.0 << endl;

    return 0;
}
