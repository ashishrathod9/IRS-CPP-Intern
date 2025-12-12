#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "enter menu choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "you selected dosa" << endl;
            break;
        case 2:
            cout << "you selected idli" << endl;
            break;
        case 3:
            cout << "you selected vada" << endl;
            break;
        default:
            cout << "invalid choice" << endl;
    }
    
    return 0;
}