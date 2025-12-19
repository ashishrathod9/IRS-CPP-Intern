#include <iostream>
#include <thread>
#include <future>

using namespace std;

#define ull unsigned long long

void findOdd(promise<ull>&& oddSumPromise, ull start, ull end) {
    ull oddSum = 0;

    for (ull i = start; i <= end; ++i) {
        if (i & 1) {
            oddSum += i;
        }
    }

    oddSumPromise.set_value(oddSum);
}

int main() {
    ull start = 0, end = 190000000;

    promise<ull> oddSumPromise;
    future<ull> oddFuture = oddSumPromise.get_future();

    cout << "thread created" << endl;

    thread t1(findOdd, move(oddSumPromise), start, end);

    cout << "waiting for result" << endl;

    cout << "OddSum = " << oddFuture.get() << endl;

    cout << "completed" << endl;

    t1.join();

    return 0;
}
