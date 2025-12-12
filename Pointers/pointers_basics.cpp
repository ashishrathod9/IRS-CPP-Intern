#include <iostream>
using namespace std;

int main() {
    int marks = 85;
    int* ptr = &marks;  
    
    cout << "marks value: " << marks << endl;
    cout << "marks address: " << &marks << endl;
    cout << "pointer value: " << ptr << endl;
    cout << "value at pointer: " << *ptr << endl;  
    
    
    int rollnumbers[] = {101, 102, 103};
    int* p = rollnumbers;
    
    cout << "roll numbers: ";
    int i;
    for (i = 0; i < 3; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
    
    return 0;
}