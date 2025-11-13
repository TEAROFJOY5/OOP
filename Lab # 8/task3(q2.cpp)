/*
Yes, a friend function can be used if the class object appears on left side of the operator.
For example, object + int or int + object both can be handled only if we use a friend function (since a member function can’t handle primitive type as left operand).
 */
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend Complex operator+(const Complex &c, double val);

    friend Complex operator+(double val, const Complex &c);

    void display() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }
};

// Object + double
Complex operator+(const Complex &c, double val) {
    Complex temp;
    temp.real = c.real + val;
    temp.imag = c.imag;
    return temp;
}

// double + Object
Complex operator+(double val, const Complex &c) {
    Complex temp;
    temp.real = c.real + val;
    temp.imag = c.imag;
    return temp;
}

int main() {
    Complex c1(4.5, 3.2);
    double num = 2.5;

    cout << "Original Complex Number: ";
    c1.display();

    Complex c2 = c1 + num; // object + double
    Complex c3 = num + c1; // double + object

    cout << "\nAfter c1 + num:" << endl;
    c2.display();

    cout << "\nAfter num + c1:" << endl;
    c3.display();

    return 0;
}


