#include <iostream>
#include <stdexcept>
#include <climits>
using namespace std;

int factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    if (result > INT_MAX) {
        throw range_error("Factorial result out of int range");
    }
    return static_cast<int>(result);
}

int main() {
    try {
        cout << factorial(20);
    }
    catch (const range_error& e) {
        cout << "Range error: " << e.what();
    }
}


