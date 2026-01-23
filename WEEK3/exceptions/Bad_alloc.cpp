#include <iostream>
#include <new>
using namespace std;

int main() {
    try {
        int* p = new int[1000000000000];
    }
    catch (const bad_alloc& e) {
        cout << "bad_alloc: " << e.what();
    }
}
