#include <iostream>
using namespace std;

int add(int a, int b);
void makeHundred(int &x);
void makeTwoHundred(int *p);
int area(int a);
int area(int a, int b);
int factorial(int n);
void greet();
void caller(void (*fp)());

int main() {
    cout << "--- Function Demonstration Program ---\n\n";

    int a = 5, b = 10;
    cout << "add(5,10) = " << add(a, b) << endl;

    int x = 10;
    makeHundred(x);
    cout << "After makeHundred(x), x = " << x << endl;

    int y = 20;
    makeTwoHundred(&y);
    cout << "After makeTwoHundred(&y), y = " << y << endl;

    cout << "Area of square (side 4) = " << area(4) << endl;
    cout << "Area of rectangle (4x6) = " << area(4, 6) << endl;

    cout << "Factorial of 5 = " << factorial(5) << endl;

    cout << "\nCalling greet() using callback:\n";
    caller(greet);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

void makeHundred(int &x) {
    x = 100;
}

void makeTwoHundred(int *p) {
    *p = 200;
}

int area(int a) {
    return a * a;
}

int area(int a, int b) {
    return a * b;
}

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

void greet() {
    cout << "Hello from callback function!" << endl;
}

void caller(void (*fp)()) {
    fp();
}
