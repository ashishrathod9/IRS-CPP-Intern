#include <iostream>
using namespace std;

void make100(int &x);
void make200(int *p);
void caller(void (*fp)());
void greet();

int main() {
    int a = 10;
    int *p = &a;
    int &r = a;

    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "r = " << r << endl;

    make100(a);
    cout << "After make100(a): " << a << endl;

    make200(&a);
    cout << "After make200(&a): " << a << endl;

    int arr[3] = {10, 20, 30};
    int *ptr = arr;
    cout << "Pointer arithmetic: ";
    cout << *ptr << " ";
    ptr++;
    cout << *ptr << " ";
    ptr++;
    cout << *ptr << endl;

    caller(greet);

    return 0;
}

void make100(int &x) {
    x = 100;
}

void make200(int *p) {
    *p = 200;
}

void greet() {
    cout << "Hello from callback!" << endl;
}

void caller(void (*fp)()) {
    fp();
}
