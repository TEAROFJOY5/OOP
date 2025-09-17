#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;
    char grade;

public:
    Student(string n, int r, double m) {
        name = n;
        rollNo = r;
        marks = m;
        grade = ' '; 
    }

    void calculateGrade() {
        if (marks >= 90)
            grade = 'A';
        else if (marks >= 80)
            grade = 'B';
        else if (marks >= 70)
            grade = 'C';
        else
            grade = 'F';
    }

    void displayStudentInfo() {
        cout << "Name: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << grade << endl;
    } 
};

int main() {
    Student s1("Ali", 101, 85.5);
    Student s2("Timur", 102, 68.0);

    s1.calculateGrade();
    s2.calculateGrade();

    s1.displayStudentInfo();
    s2.displayStudentInfo();

    return 0;
}
