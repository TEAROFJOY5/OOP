#include <iostream>
#include <string>
using namespace std;
class ClassSchedule {
private:
    string days;
    string time;
public:
    ClassSchedule(string d, string t) : days(d), time(t) {}

    void displaySchedule() const {
        cout << "Schedule: " << days << " at " << time << endl;
    }
};
class Student {
private:
    const string enrollmentID;
    string name;
public:
    Student(string id, string n) : enrollmentID(id), name(n) {}

    void displayStudent() const {
        cout << "Enrollment ID: " << enrollmentID << ", Name: " << name << endl;
    }
};
class CourseSection {
private:
    string sectionName;
    ClassSchedule schedule;
    Student* students[48];
    int studentCount;
    static int totalSections;
public:
    CourseSection(string name, string days, string time) 
        : sectionName(name), schedule(days, time), studentCount(0) {
        totalSections++;
    }
    void addStudent(Student* s) {
        if (studentCount < 50) {
            students[studentCount++] = s;
        }
    }
    void displaySection() const {
        cout << "Course Section: " << sectionName << endl;
        schedule.displaySchedule();
        cout << "Enrolled Students:\n";
        for (int i = 0; i < studentCount; ++i) {
            students[i]->displayStudent();
        }
    }
    static void displayTotalSections() {
        cout << "Total Course Sections Offered: " << totalSections << endl;
    }
};
int CourseSection::totalSections = 0;

int main() {
    Student s1("22-CS-001", "Turab");
    Student s2("22-CS-002", "Taqi");
    Student s3("22-CS-003", "Hassan");

    CourseSection sec1("BCS-A", "Mon-Wed-Fri", "9:00 AM - 11:00 AM");
    sec1.addStudent(&s1);
    sec1.addStudent(&s2);

    CourseSection sec2("BCS-B", "Tue-Thu", "11:00 AM - 1:00 PM");
    sec2.addStudent(&s3);

    sec1.displaySection();
    cout << "\n";
    sec2.displaySection();
    cout << "\n";
    CourseSection::displayTotalSections();
    return 0;
}
