#include <iostream>
using namespace std;

int main()
{
    int num = 42;
    int* ptr = &num;
    
    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value stored in ptr (address): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    cout << endl;
    
    *ptr = 100;
    cout << "After *ptr = 100:" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    cout << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;
    
    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(arrPtr + " << i << ") = " << *(arrPtr + i) << endl;
    }
    cout << endl;
    
    int value = 25;
    int* p1 = &value;
    int** p2 = &p1;
    
    cout << "Value: " << value << endl;
    cout << "Using *p1: " << *p1 << endl;
    cout << "Using **p2: " << **p2 << endl;
    cout << endl;
    
    int* nullPtr = nullptr;
    
    if (nullPtr == nullptr) {
        cout << "nullPtr is not pointing to anything" << endl;
    }
    cout << endl;
    
    return 0;
}
