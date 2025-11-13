/*
  Answer:
No, a friend function cannot directly modify the invoking object (this), because it is not a member function — hence, it does not have a this pointer.
However, it can modify the object if it receives it by reference.

*/
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function to overload += operator
    friend Complex &operator+=(Complex &lhs, const Complex &rhs);

    void display() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }
};

// Friend function implementation
Complex &operator+=(Complex &lhs, const Complex &rhs) {
    lhs.real += rhs.real;
    lhs.imag += rhs.imag;
    return lhs;
}

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.0);

    cout << "Before addition: " << endl;
    c1.display();
    c2.display();

    c1 += c2; // modifies left-hand operand through friend function

    cout << "\nAfter c1 += c2:" << endl;
    c1.display();

    return 0;
}
