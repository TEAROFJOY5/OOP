#include <iostream>
#include <cstring>  // For strcpy
using namespace std;

class Student {
private:
    int studentID;
    char name[50];
    bool cardActive;
    char routeAssigned[100];

public:
    // Constructor - student ka record banane ke liye
    Student(int id = 0, const char n[] = "") {
        studentID = id;
        strcpy(name, n);
        cardActive = false;
        strcpy(routeAssigned, "None");
    }

    // Copy constructor - kisi student ka duplicate banane ke liye
    Student(const Student &s) {
        studentID = s.studentID;
        strcpy(name, s.name);
        cardActive = s.cardActive;
        strcpy(routeAssigned, s.routeAssigned);
    }

    // Destructor - jab object delete hoga
    ~Student() {
        cout << "Student " << name << " removed from system.\n";
    }

    // Getters
    int getID() const { return studentID; }
    const char* getName() const { return name; }
    bool isCardActive() const { return cardActive; }
    const char* getRoute() const { return routeAssigned; }

    // Route set karne ka function
    void setRoute(const char route[]) {
        strcpy(routeAssigned, route);
    }

    // Register for service
    void registerService() {
        cout << name << " registered for transportation.\n";
    }

    // Semester fee pay karne ka function
    void payFees() {
        cardActive = true;
        cout << name << " has paid fees. Card is now active.\n";
    }
};

class Route {
private:
    int routeID;
    char pickupStop[50];
    char dropStop[50];

public:
    // Constructor - route banane ke liye
    Route(int id = 0, const char pick[] = "", const char drop[] = "") {
        routeID = id;
        strcpy(pickupStop, pick);
        strcpy(dropStop, drop);
    }

    // Route show karne ka function
    void showRoute() {
        cout << "Route " << routeID << ": " << pickupStop << " -> " << dropStop << endl;
    }

    // Getters
    const char* getPickup() const { return pickupStop; }
    const char* getDrop() const { return dropStop; }
};

class Bus {
private:
    int busID;
    int capacity;
    int currentStudents;

public:
    // Constructor
    Bus(int id = 0, int cap = 0) {
        busID = id;
        capacity = cap;
        currentStudents = 0;
    }
    // Attendance mark karne ka function
    void recordAttendance(Student &s) {
        if (s.isCardActive() && currentStudents < capacity) {
            currentStudents++;
            cout << "Attendance marked for " << s.getName() << " on Bus " << busID << endl;
        } else {
            cout << "Attendance failed for " << s.getName() << endl;
        }
    }
};
class TransportationSystem {
private:
    static int totalStudents; // System-wide shared value
public:
    // Student ko route assign karne ka function
    void assignRoute(Student &s, Route &r) {
        char fullRoute[100];
        strcpy(fullRoute, r.getPickup());
        strcat(fullRoute, " -> ");
        strcat(fullRoute, r.getDrop());
        s.setRoute(fullRoute);
        totalStudents++;
        cout << s.getName() << " assigned to route " << s.getRoute() << endl;
    }
    // Total students system mein show karne ka function
    static void showTotalStudents() {
        cout << "Total students in system: " << totalStudents << endl;
    }
};
// Initialize static variable
int TransportationSystem::totalStudents = 0;

int main() {
    // Students banaye
    Student s1(101, "Ali");
    Student s2(102, "Turab");
    // Routes banaye
    Route r1(1, "Maymar", "FAST");
    Route r2(2, "Saddar", "FAST");
    // Bus banaya with capacity 2
    Bus b1(1, 2);
    // Transport system object
    TransportationSystem ts;
    // Student 1 actions
    s1.registerService();
    s1.payFees();
    ts.assignRoute(s1, r1);
    // Student 2 actions
    s2.registerService();
    s2.payFees();
    ts.assignRoute(s2, r2);
    // Attendance mark ki
    b1.recordAttendance(s1);
    b1.recordAttendance(s2);
    // Show total students in system
    TransportationSystem::showTotalStudents();
    return 0;
}
