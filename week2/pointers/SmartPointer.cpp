#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
public:
    int length;
    int breadth;

    Rectangle(int l, int b) : length(l), breadth(b) {}
    Rectangle() : Rectangle(1, 2) {}
};

void uniqueExample() {
    unique_ptr<Rectangle> r1(new Rectangle(10, 2));
    cout << "Unique: " << r1->length << " " << r1->breadth << endl;

    unique_ptr<Rectangle> r2 = move(r1);
}

void sharedExample() {
    shared_ptr<Rectangle> s1 = make_shared<Rectangle>(5, 5);
    cout << "Shared count: " << s1.use_count() << endl;

    {
        shared_ptr<Rectangle> s2 = s1;
        cout << "Shared count inside block: " << s1.use_count() << endl;
    }

    cout << "Shared count after block: " << s1.use_count() << endl;
}

void weakExample() {
    shared_ptr<Rectangle> s1 = make_shared<Rectangle>(3, 4);
    weak_ptr<Rectangle> w1 = s1;

    cout << "Weak expired? " << w1.expired() << endl;

    s1.reset();
    cout << "Weak expired after reset? " << w1.expired() << endl;
}

int main() {
    uniqueExample();
    sharedExample();
    weakExample();
}
