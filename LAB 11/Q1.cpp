#include <iostream>
using namespace std;

class Vehicle {
protected:
    double speed;
    int capacity;
    string fuel;
public:
    Vehicle(double s, int c, const string& f) : speed(s), capacity(c), fuel(f) {}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double calculateEnergyConsumption() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(double s, int c, const string& f) : Vehicle(s, c, f) {}
    void start() override { cout << "Car starting\n"; }
    void stop() override { cout << "Car stopping\n"; }
    double calculateEnergyConsumption() override { return speed * 0.22 + capacity * 0.08; }
};

class Bus : public Vehicle {
public:
    Bus(double s, int c, const string& f) : Vehicle(s, c, f) {}
    void start() override { cout << "Bus starting\n"; }
    void stop() override { cout << "Bus stopping\n"; }
    double calculateEnergyConsumption() override { return speed * 0.47 + capacity * 0.35; }
};

class ElectricBike : public Vehicle {
public:
    ElectricBike(double s, int c, const string& f) : Vehicle(s, c, f) {}
    void start() override { cout << "E-Bike starting\n"; }
    void stop() override { cout << "E-Bike stopping\n"; }
    double calculateEnergyConsumption() override { return speed * 0.12; }
};

int main() {
    Vehicle* v1 = new Car(75, 5, "Petrol");
    Vehicle* v2 = new Bus(55, 50, "Diesel");
    Vehicle* v3 = new ElectricBike(22, 1, "Electric");

    v1->start();
    cout << v1->calculateEnergyConsumption() << "\n";
    v1->stop();

    cout << "------\n";

    v2->start();
    cout << v2->calculateEnergyConsumption() << "\n";
    v2->stop();

    cout << "------\n";

    v3->start();
    cout << v3->calculateEnergyConsumption() << "\n";
    v3->stop();

    delete v1;
    delete v2;
    delete v3;

    return 0;
}
