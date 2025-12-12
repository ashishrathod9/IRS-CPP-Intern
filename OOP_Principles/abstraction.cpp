#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;  
    virtual void display() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    
    double area() {
        double result = width * height;
        return result;
    }
    
    void display() {
        double shapearea = area();
        cout << "rectangle: " << width << "x" << height << ", area: " << shapearea << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) {
        radius = r;
    }
    
    double area() {
        double result = 3.14159 * radius * radius;
        return result;
    }
    
    void display() {
        double shapearea = area();
        cout << "circle: radius " << radius << ", area: " << shapearea << endl;
    }
};

int main() {
    Rectangle rect(8, 5);
    Circle circle(6);
    
    rect.display();
    circle.display();
    
    return 0;
}