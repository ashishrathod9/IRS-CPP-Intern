#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        double x = 1e-308;
        if (x < 1e-300)
            throw underflow_error("Floating underflow");
    }
    catch (const underflow_error& e) {
        cout << e.what();
    }
}

