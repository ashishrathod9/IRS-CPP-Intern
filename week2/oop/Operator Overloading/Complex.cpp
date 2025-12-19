#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    void display() const {
        cout << real << "+i" << img << endl;
    }

    // Addition operator
    Complex operator+(const Complex &c1) const {
        return Complex(real + c1.real, img + c1.img);
    }

    // Multiplication operator
    friend Complex operator*(const Complex &c1, const Complex &c2);

    // Output operator
    friend ostream& operator<<(ostream &out, const Complex &c);

    // Input operator
    friend istream& operator>>(istream &in, Complex &c);
};

// Correct multiplication formula
Complex operator*(const Complex &c1, const Complex &c2) {
    return Complex(
        c1.real * c2.real - c1.img * c2.img,
        c1.real * c2.img + c1.img * c2.real
    );
}

ostream& operator<<(ostream &out, const Complex &c) {
    out << c.real << "+i" << c.img;
    return out;
}

istream& operator>>(istream &in, Complex &c) {
    in >> c.real >> c.img;
    return in;
}

int main() {
    Complex c1(5, 3), c2(12, 3), c3;

    c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Multiplication: " << c3 << endl;

    return 0;
}
