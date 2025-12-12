#include <iostream>
using namespace std;

int add(int num1, int num2) { 
    int result = num1 + num2;
    return result; 
}

int multiply(int num1, int num2) { 
    int result = num1 * num2;
    return result; 
}

int calculate(int x, int y, int (*operation)(int, int)) {
    int result = operation(x, y);
    return result;
}

int main() {
    int sum = calculate(8, 3, add);
    int product = calculate(8, 3, multiply);
    
    cout << "addition: " << sum << endl;
    cout << "multiplication: " << product << endl;
    
    return 0;
}