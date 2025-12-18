#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

// --------------------------------------------------
// 1. BASIC MUTEX
// --------------------------------------------------
mutex printMutex;

void basicMutexTask(int id)
{
    lock_guard<mutex> lock(printMutex);
    cout << "[Basic Mutex] Thread " << id << " printing\n";
}

// --------------------------------------------------
// 2. try_lock()
// --------------------------------------------------
mutex tryMutex;

void tryLockTask(int id)
{
    if (tryMutex.try_lock())
    {
        cout << "[try_lock] Thread " << id << " got lock\n";
        tryMutex.unlock();
    }
    else
    {
        cout << "[try_lock] Thread " << id << " failed\n";
    }
}

// --------------------------------------------------
// 3. timed_mutex
// --------------------------------------------------
timed_mutex timedMtx;

void timedMutexTask()
{
    if (timedMtx.try_lock_for(seconds(1)))
    {
        cout << "[timed_mutex] Lock acquired\n";
        this_thread::sleep_for(seconds(2));
        timedMtx.unlock();
    }
    else
    {
        cout << "[timed_mutex] Timeout\n";
    }
}

// --------------------------------------------------
// 4. recursive_mutex
// --------------------------------------------------
recursive_mutex recMtx;

void recursiveTask(int level)
{
    lock_guard<recursive_mutex> lock(recMtx);
    cout << "[recursive_mutex] Level " << level << endl;

    if (level > 0)
        recursiveTask(level - 1);
}

// --------------------------------------------------
// 5. shared_mutex (Readers & Writer)
// --------------------------------------------------
shared_mutex sharedMtx;

void reader(int id)
{
    sharedMtx.lock_shared();
    cout << "[shared_mutex] Reader " << id << " reading\n";
    this_thread::sleep_for(milliseconds(200));
    sharedMtx.unlock_shared();
}

void writer()
{
    sharedMtx.lock();
    cout << "[shared_mutex] Writer updating\n";
    this_thread::sleep_for(milliseconds(500));
    sharedMtx.unlock();
}

// --------------------------------------------------
// 6. std::try_lock (Deadlock Free)
// --------------------------------------------------
mutex fileA, fileB;

void backupTask()
{
    int result = try_lock(fileA, fileB);

    if (result == -1)
    {
        cout << "[std::try_lock] Both files locked safely\n";
        fileA.unlock();
        fileB.unlock();
    }
    else
    {
        cout << "[std::try_lock] Could not lock both files\n";
    }
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()
{
    cout << "\n--- Thread & Mutex Demo (Single File) ---\n\n";

    // 1. Basic mutex
    thread t1(basicMutexTask, 1);
    thread t2(basicMutexTask, 2);
    t1.join(); t2.join();

    cout << endl;

    // 2. try_lock
    thread t3(tryLockTask, 1);
    thread t4(tryLockTask, 2);
    t3.join(); t4.join();

    cout << endl;

    // 3. timed_mutex
    thread t5(timedMutexTask);
    thread t6(timedMutexTask);
    t5.join(); t6.join();

    cout << endl;

    // 4. recursive_mutex
    thread t7(recursiveTask, 3);
    t7.join();

    cout << endl;

    // 5. shared_mutex
    thread r1(reader, 1);
    thread r2(reader, 2);
    thread w(writer);
    r1.join(); r2.join(); w.join();

    cout << endl;

    // 6. std::try_lock
    thread t8(backupTask);
    thread t9(backupTask);
    t8.join(); t9.join();

    cout << "\n--- Demo Finished ---\n";
    return 0;
}
