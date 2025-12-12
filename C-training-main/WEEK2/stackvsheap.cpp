#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int *p = new int;
    *p = 20;

    cout << a << endl;
    cout << *p << endl;

    delete p;

    return 0;
}
