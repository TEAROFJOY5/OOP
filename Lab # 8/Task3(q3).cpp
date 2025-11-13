/*
No, a friend function needs an object to access private or protected data.
Even though it has permission, it still must access members through an object — it cannot access them directly without one.
 */

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend void showPrivate(const Complex &c);
    friend void tryAccessWithoutObject(); 
    void display() const {
        cout << "Complex Number: " << real << " + " << imag << "i" << endl;
    }
};
void showPrivate(const Complex &c) {
    cout << "Accessing private members using object: " << endl;
    cout << "Real = " << c.real << ", Imaginary = " << c.imag << endl;
}

void tryAccessWithoutObject() {
    
    cout << "Cannot access private data without an object of the class!" << endl;
}

int main() {
    Complex c1(5.2, 3.8);

    cout << "Displaying normally: ";
    c1.display();

    cout << endl;
    showPrivate(c1); 
    cout << endl;
    tryAccessWithoutObject(); 
    return 0;
}

