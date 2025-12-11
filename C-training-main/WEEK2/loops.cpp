#include <iostream>
using namespace std;

int main() {
    string pass;
    int attempts = 3;

    while(attempts > 0) {
        cout << "Enter password: ";
        cin >> pass;

        if(pass == "1234") {
            cout << "Login Successful";
            break;
        }
        attempts--;

        cout << "Wrong! Attempts left: " << attempts << endl;
    }
}
