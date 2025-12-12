#include <iostream>
using namespace std;

// function declaration
int add(int num1, int num2);
void greet(string name);

// pass by value vs pass by reference
void changevalue(int x);
void changereference(int& x);

// function overloading
int multiply(int num1, int num2);
double multiply(double num1, double num2);

int main() {
    int result = add(10, 5);
    cout << "sum: " << result << endl;
    greet("ravi");
    
    int number = 20;
    cout << "before changevalue: " << number << endl;
    changevalue(number);
    cout << "after changevalue: " << number << endl;
    
    cout << "before changereference: " << number << endl;
    changereference(number);
    cout << "after changereference: " << number << endl;
    
    int intresult = multiply(3, 4);
    double doubleresult = multiply(2.5, 3.0);
    cout << "int multiply: " << intresult << endl;
    cout << "double multiply: " << doubleresult << endl;
    
    return 0;
}

// function definitions
int add(int num1, int num2) {
    int sum = num1 + num2;
    return sum;
}

void greet(string name) {
    cout << "namaste " << name << "!" << endl;
}

void changevalue(int x) {
    x = 100;
}

void changereference(int& x) {
    x = 100;
}

int multiply(int num1, int num2) {
    int result = num1 * num2;
    return result;
}

double multiply(double num1, double num2) {
    double result = num1 * num2;
    return result;
}