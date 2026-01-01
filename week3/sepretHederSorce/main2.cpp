#include "Student.h"
#include <iostream>

int main() {
    Student student1("Alice Johnson", 12345, 3.8);

    student1.displayInfo();

    student1.setGpa(3.9);
    std::cout << "\nAfter GPA update:\n";
    student1.displayInfo();

    return 0;
}
