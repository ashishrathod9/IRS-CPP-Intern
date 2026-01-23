#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;

    try {
        if (age < 0) {
            throw invalid_argument("Age cannot be negative");
        }
        cout << "Age is valid";
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what();
    }
}
