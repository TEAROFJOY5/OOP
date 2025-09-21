#include<iostream>
using namespace std;

class Patient {
    // Private attributes - sensitive info is hidden
    int patientID;
    string Name;
    int Age;
    double billAmount;

public:
    // Constructor - naya patient record banane ke liye
    Patient(int id, string name, int age, double bill)
        : patientID(id), Name(name), Age(age), billAmount(bill) {}

    // Copy Constructor - patient record duplicate karne ke liye
    Patient(const Patient &p) {
        patientID = p.patientID;
        Name = p.Name;
        Age = p.Age;
        billAmount = p.billAmount;
    }

    // Setters - private data ko update karne ke liye
    void setID(int id) { patientID = id; }
    void setName(string name) { Name = name; }
    void setAge(int age) { Age = age; }
    void setBill(double bill) { billAmount = bill; }

    // Getters - private data ko access karne ke liye
    int getID() { return patientID; }
    string getName() { return Name; }
    int getAge() { return Age; }
    double getBill() { return billAmount; }

    // Treatment charges add karne ka function
    void treatmentCharges(double charges) {
        billAmount += charges;
        cout << "Updated Bill Amount (PKR): " << billAmount << endl;
    }

    // Patient ki details show karne ka function
    void Display() {
        cout << "\n--- Patient Details ---" << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << " years" << endl;
        cout << "Bill Amount (PKR): " << billAmount << endl;
    }
};

int main() {
    // Naya patient banaya using dynamic memory
    Patient* p1 = new Patient(101, " Turab", 19, 40000);

    // Treatment charges add kiye
    p1->treatmentCharges(5600);   // PKR 5600 ka treatment
    p1->Display();

    p1->treatmentCharges(5000);   // PKR 5000 ka additional treatment
    p1->Display();

    // Patient ka record copy kiya (e.g. for discharge summary)
    Patient* p2 = new Patient(*p1);

    // Copied record show kiya
    p2->Display();

    // Memory free ki (important in dynamic allocation)
    delete p1;
    delete p2;

    return 0;
}
