#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// functor (function object)
class Base {
public:
    void operator()(int x) {
        while (x-- > 0) {
            cout << "functor: " << x << endl;
        }
    }

    // non-static member function
    void run(int x) {
        while (x-- > 0) {
            cout << "member: " << x << endl;
        }
    }

    // static member function
    static void runStatic(int x) {
        while (x-- > 0) {
            cout << "static: " << x << endl;
        }
    }
};

// free function
void fun(int x) {
    while (x-- > 0) {
        cout << "free: " << x << endl;
    }
}

int main() {

    thread t1(fun, 10);
    t1.join();

    thread t2([](int x){
        while (x-- > 0) {
            cout << "lambda: " << x << endl;
        }
    }, 10);
    t2.join();

    thread t3(Base(), 10);   // functor
    t3.join();

    Base b;
    thread t4(&Base::run, &b, 10);  // non-static member function
    t4.join();

    thread t5(&Base::runStatic, 10); // static member function
    t5.join();

    return 0;
}
