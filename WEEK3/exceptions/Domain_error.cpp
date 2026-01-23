#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

int main() {
    try {
        double x = -1;
        if (x < 0)
            throw domain_error("sqrt of negative number");
        cout << sqrt(x);
    }
    catch (const domain_error& e) {
        cout << e.what();
    }
}
