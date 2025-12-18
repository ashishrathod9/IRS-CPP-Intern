#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull Oddsum = 0;
ull Evensum = 0;

void findeven(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            Evensum += i;
        }
    }
}

void findodd(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)   // FIXED
        {
            Oddsum += i;
        }
    }
}

int main()
{
    ull start = 0, end = 1900000000;

    auto t1_start = high_resolution_clock::now();

    // Create threads
    thread t1(findeven, start, end);
    thread t2(findodd, start, end);

    // Wait for threads to finish
    t1.join();
    t2.join();

    auto t1_end = high_resolution_clock::now();

    cout << "Odd Sum  = " << Oddsum << endl;
    cout << "Even Sum = " << Evensum << endl;

    cout << "Time taken: "
         << duration_cast<seconds>(t1_end - t1_start).count()
         << " seconds" << endl;

    return 0;
}
