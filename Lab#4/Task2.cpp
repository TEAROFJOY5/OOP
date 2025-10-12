#include <iostream>
#include <string>
using namespace std;

class NUCES_Student {
private:
    int id;
    string name;

public:
    // Default Constructor
    NUCES_Student() {
        id = 0;
        name = "Not Registered";
    }

    // Parameterized Constructor (Version 1): ID only
    NUCES_Student(int id) {
        this->id = id;
        name = "Name Pending";
    }

    // Parameterized Constructor (Version 2): ID and Name
    NUCES_Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void display() const {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

int main() {
    cout << "Default Student:\n";
    NUCES_Student s1;
    s1.display();

    cout << "\nStudent with ID only:\n";
    NUCES_Student s2(12345);
    s2.display();

    cout << "\nStudent with ID and Name:\n";
    NUCES_Student s3(67890, "Areeba Khan");
    s3.display();

    return 0;
}
