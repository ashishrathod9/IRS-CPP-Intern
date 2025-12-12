#include <iostream>
#include <string>
using namespace std;

int main() {
    int marks[5] = {85, 92, 78, 88, 95};
    cout << "student marks: ";
    int i;
    for (i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
    
    string firstname = "ravi";
    string lastname = "kumar";
    string fullname = firstname + " " + lastname;
    
    cout << "full name: " << fullname << endl;
    cout << "name length: " << fullname.length() << endl;
    cout << "first name: " << fullname.substr(0, 4) << endl;
    
    return 0;
}