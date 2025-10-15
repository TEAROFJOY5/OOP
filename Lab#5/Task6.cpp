#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    string name;
    int id;
    static int totalEmployees;
public:
    Employee(string empName, int empID) {
        name = empName;
        id = empID;
        totalEmployees++;
    }
    string getName() const {
        return name;
    }
    int getID() const {
        return id;
    }
    static int getTotalEmployees() {
        return totalEmployees;
    }
};
int Employee::totalEmployees = 0;
class ClientProject {
private:
    Employee* team[10];
    int teamSize;
public:
    ClientProject() {
        teamSize = 0;
    }
    void assignEmployee(Employee* emp) {
        if (teamSize < 10) {
            team[teamSize++] = emp;
        }
    }
    void displayTeam() const {
        cout << "Project Team Members:\n";
        for (int i = 0; i < teamSize; ++i) {
            cout << "ID: " << team[i]->getID() << ", Name: " << team[i]->getName() << endl;
        }
    }
};
int main() {
    Employee emp1("Turab", 101);
    Employee emp2("Ali", 102);
    Employee emp3("taqi", 103);
    ClientProject project1;
    project1.assignEmployee(&emp1);
    project1.assignEmployee(&emp2);
    project1.assignEmployee(&emp3);
    project1.displayTeam();
    cout << "Total company employees: " << Employee::getTotalEmployees() << endl;
    return 0;
}
