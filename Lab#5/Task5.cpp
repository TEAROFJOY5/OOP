#include <iostream>
#include <string>
using namespace std;

class Kitchen {
private:
    float area;
    bool gasConnection;

public:
    Kitchen(float a, bool gas) : area(a), gasConnection(gas) {}

    void displayKitchen() const {
        cout << "Kitchen Area: " << area << " sq.ft, Gas Connection: " 
             << (gasConnection ? "Yes" : "No") << endl;
    }
};

class Apartment {
private:
    const int apartmentID;
    int floorNumber;
    Kitchen kitchen;

public:
    Apartment(int id, int floor, float kitchenArea, bool gas)
        : apartmentID(id), floorNumber(floor), kitchen(kitchenArea, gas) {}

    void displayApartment() const {
        cout << "Apartment ID: " << apartmentID << ", Floor: " << floorNumber << endl;
        kitchen.displayKitchen();
    }
};

int main() {
    Apartment flat1(122, 3, 32.5, true);
    Apartment flat2(123, 4, 86.0, false);

    flat1.displayApartment();
    cout << endl;
    flat2.displayApartment();

    return 0;
}
