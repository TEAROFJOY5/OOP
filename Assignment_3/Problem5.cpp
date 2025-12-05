#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pet {
public:
    T name;
    int age;

    Pet(T n, int a) : name(n), age(a) {}
    virtual void makeSound() = 0;  // pure virtual
    virtual void showInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Cat : public Pet<string> {
public:
    Cat(string n, int a) : Pet(n, a) {}
    void makeSound() override {
        cout << "Meow" << endl;
    }
};

class Dog : public Pet<string> {
public:
    Dog(string n, int a) : Pet(n, a) {}
    void makeSound() override {
        cout << "Woof" << endl;
    }
};

class Bird : public Pet<string> {
public:
    Bird(string n, int a) : Pet(n, a) {}
    void makeSound() override {
        cout << "Chirp" << endl;
    }
};

int main() {
    Cat c1("Whiskers", 3);
    Dog d1("Buddy", 5);
    Bird b1("Tweety", 1);

    Pet<string>* pets[3];
    pets[0] = &c1;
    pets[1] = &d1;
    pets[2] = &b1;

    for (int i = 0; i < 3; i++) {
        (*pets[i]).showInfo();
        (*pets[i]).makeSound();
        cout << endl;
    }

    return 0;
}
