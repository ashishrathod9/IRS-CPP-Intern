#include <iostream>
#include "circle.h"

using namespace std;

void Circle::accept() {
    cout << "Enter radius: ";
    cin >> radius;
}

void Circle::showArea() {
    cout << "Area = " << 3.14 * radius * radius << endl;
}

void Circle::showPeri() {
    cout << "Perimeter = " << 2 * 3.14 * radius << endl;
}
