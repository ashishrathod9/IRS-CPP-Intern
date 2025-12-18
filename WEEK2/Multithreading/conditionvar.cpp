#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
const unsigned int maxBufferSize = 10;
bool done = false;

// Producer function
void producer(int id) {
    for (int i = 0; i < 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < maxBufferSize; }); // Wait if buffer is full
        
        buffer.push(i); // Produce an item
        std::cout << "Producer " << id << " produced " << i << std::endl;
        
        lock.unlock();
        cv.notify_all(); // Notify consumers
    }
    
    // After producing all items, mark as done
    if (id == 0) {
        std::lock_guard<std::mutex> guard(mtx);
        done = true;
        cv.notify_all(); // Notify one last time to unblock consumers
    }
}

// Consumer function
void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty() || done; }); // Wait if buffer is empty and not done
        
        if (!buffer.empty()) {
            int value = buffer.front();
            buffer.pop();
            std::cout << "Consumer " << id << " consumed " << value << std::endl;
            lock.unlock();
            cv.notify_all(); // Notify producers
        } else if (done) {
            break; // Exit if done and buffer is empty
        }
    }
}

int main() {
    std::thread p1(producer, 1);
    std::thread p2(producer, 2);
    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();
    
    return 0;
}
