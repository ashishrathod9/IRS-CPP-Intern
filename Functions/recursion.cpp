#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    int result = n * factorial(n - 1);
    return result;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int result = fibonacci(n - 1) + fibonacci(n - 2);
    return result;
}

int main() {
    int num = 5;
    int fact = factorial(num);
    cout << "factorial of " << num << ": " << fact << endl;
    
    int fibnum = 6;
    int fib = fibonacci(fibnum);
    cout << "fibonacci of " << fibnum << ": " << fib << endl;
    
    return 0;
}