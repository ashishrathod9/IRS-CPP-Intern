#include <iostream>
using namespace std;

int main() {
    int num1 = 15;
    int num2 = 4;
    
    
    int sum = num1 + num2;
    int diff = num1 - num2;
    int product = num1 * num2;
    int division = num1 / num2;
    int remainder = num1 % num2;
    
    cout << "addition: " << sum << endl;
    cout << "subtraction: " << diff << endl;
    cout << "multiplication: " << product << endl;
    cout << "division: " << division << endl;
    cout << "modulus: " << remainder << endl;
    
    
    bool isgreater = num1 > num2;
    bool isequal = num1 == num2;
    
    cout << "15 > 4: " << isgreater << endl;
    cout << "15 == 4: " << isequal << endl;
    
    
    bool ravi_pass = true;
    bool sita_pass = false;
    
    cout << "both pass: " << (ravi_pass && sita_pass) << endl;
    cout << "any pass: " << (ravi_pass || sita_pass) << endl;
    
    return 0;
}