#include <iostream>
#include <string>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;

public:
    Doctor(string n, string s) : name(n), specialization(s) {}

    void displayDoctor() const {
        cout << "Doctor: " << name << ", Specialization: " << specialization << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctors[10];
    int doctorCount;

public:
    Hospital(string name) : hospitalName(name), doctorCount(0) {}

    void addDoctor(Doctor* d) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = d;
        }
    }

    void displayHospital() const {
        cout << "Hospital: " << hospitalName << endl;
        for (int i = 0; i < doctorCount; ++i) {
            doctors[i]->displayDoctor();
        }
    }
};

int main() {
    Doctor d1("Dr. Tayyab", "Cardiologist");
    Doctor d2("Dr. Farhan", "Neurologist");

    Hospital h1("CMH");
    h1.addDoctor(&d1);
    h1.addDoctor(&d2);

    Hospital h2("Indus Hospital");
    h2.addDoctor(&d2);
    h2.addDoctor(&d1);

    h1.displayHospital();
    cout << endl;
    h2.displayHospital();

    return 0;
}
