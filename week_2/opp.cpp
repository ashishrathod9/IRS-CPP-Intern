#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
};

class Rectangle : public Shape {
    float l, b;
public:
    Rectangle(float l, float b) : l(l), b(b) {}
    float area() {
        return l * b;
    }
};

int main() {
    Shape *s = new Rectangle(10, 5);
    cout << "Area: " << s->area();
    delete s;
    return 0;
}

