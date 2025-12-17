#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    int choice, a, b;
    cout << "1.Add 2.Sub\n";
    cin >> choice;
    cin >> a >> b;

    switch (choice) {
        case 1: cout << add(a, b); break;
        case 2: cout << sub(a, b); break;
        default: cout << "Invalid";
    }
    return 0;
}

