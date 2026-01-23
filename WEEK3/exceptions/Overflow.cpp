#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int x = 100;
        if (x > 50)
            throw overflow_error("Integer overflow");
    }
    catch (const overflow_error& e) {
        cout << e.what();
    }
}
