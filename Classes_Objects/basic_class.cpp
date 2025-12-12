#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    double marks;
    
public:
    Student() {
        name = "unknown";
        age = 0;
        marks = 0.0;
    }
    
    Student(string studentname, int studentage, double studentmarks) {
        name = studentname;
        age = studentage;
        marks = studentmarks;
    }
    
    ~Student() {
        cout << "student " << name << " object destroyed" << endl;
    }
    
    void display() {
        cout << "name: " << name << ", age: " << age << ", marks: " << marks << endl;
    }
    
    void setmarks(double newmarks) {
        marks = newmarks;
    }
    
    double getmarks() {
        return marks;
    }
};

struct Point {  
    int x;
    int y;
    
    Point(int xval, int yval) {
        x = xval;
        y = yval;
    }
    
    void print() {
        cout << "point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Student s1;  
    Student s2("ravi", 20, 85.5);  
    
    s1.display();
    s2.display();
    
    s2.setmarks(92.0);
    double newmarks = s2.getmarks();
    cout << "ravi updated marks: " << newmarks << endl;
    
    Point p(15, 25);
    p.print();
    
    return 0;
}