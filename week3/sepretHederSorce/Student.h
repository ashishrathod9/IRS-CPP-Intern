#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int id;
    double gpa;

public:
    // Constructor
    Student(std::string name, int id, double gpa);

    // Getters
    std::string getName() const;
    int getId() const;
    double getGpa() const;

    // Setters
    void setName(std::string name);
    void setGpa(double gpa);

    // Other methods
    void displayInfo() const;
};

#endif
