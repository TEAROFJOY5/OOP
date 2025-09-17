#include <iostream>
using namespace std;

class Vehicle {
public:
    string make;
    string model;

    void displayInfo() {
        cout << "Make: " << make ;
        cout << "\nModel: " << model ;
    }
};
class Car : public Vehicle {
public:
    string engineType;

    void displayInfo() {
        Vehicle::displayInfo();  
        cout << "\nEngine Type: " << engineType ;
    }
};
int main() {
    Car myCar;
    myCar.make = "Honda";
    myCar.model = "Civics";
    myCar.engineType = "Hybrid";

    myCar.displayInfo();

    return 0;
}
