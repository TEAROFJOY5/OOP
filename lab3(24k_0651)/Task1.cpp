
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int rollNumber;
};
int main() {
    Student s;
    s.name = "Turab Ali";
    s.rollNumber = 123;
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    return 0;
}

