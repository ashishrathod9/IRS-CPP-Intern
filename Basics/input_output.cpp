#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    
    cout << "enter your name: ";
    cin >> name;
    
    cout << "enter your age: ";
    cin >> age;
    
    cout << "hello " << name << ", you are " << age << " years old!" << endl;
    
    return 0;
}