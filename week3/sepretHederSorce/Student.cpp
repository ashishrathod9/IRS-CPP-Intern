#include "Student.h"
#include <iostream>

// Constructor implementation
Student::Student(std::string name, int id, double gpa)
    : name(name), id(id), gpa(gpa) {
}

// Getter implementations
std::string Student::getName() const {
    return name;
}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

// Setter implementations
void Student::setName(std::string name) {
    this->name = name;
}

void Student::setGpa(double gpa) {
    if (gpa >= 0.0 && gpa <= 4.0) {
        this->gpa = gpa;
    }
}

// Display method implementation
void Student::displayInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "GPA: " << gpa << "\n";
}
