#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Vehicle {
protected:
    double m_speed;
    int m_capacity;
    string m_fuel;

public:
    Vehicle(double speed, int capacity, const string& fuel)
        : m_speed(speed), m_capacity(capacity), m_fuel(fuel) {}

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double calculateEnergyConsumption() = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(double speed, int capacity, const string& fuel)
        : Vehicle(speed, capacity, fuel) {}

    void start() override {
        cout << "Car: ignition on\n";
    }

    void stop() override {
        cout << "Car: engine off\n";
    }

    double calculateEnergyConsumption() override {
        return m_speed * 0.22 + m_capacity * 0.08;
    }
};

class Bus : public Vehicle {
public:
    Bus(double speed, int capacity, const string& fuel)
        : Vehicle(speed, capacity, fuel) {}

    void start() override {
        cout << "Bus: starting route\n";
    }

    void stop() override {
        cout << "Bus: stopping at station\n";
    }

    double calculateEnergyConsumption() override {
        return m_speed * 0.47 + m_capacity * 0.35;
    }
};

class ElectricBike : public Vehicle {
public:
    ElectricBike(double speed, int capacity, const string& fuel)
        : Vehicle(speed, capacity, fuel) {}

    void start() override {
        cout << "E-Bike: power on\n";
    }

    void stop() override {
        cout << "E-Bike: power off\n";
    }

    double calculateEnergyConsumption() override {
        return m_speed * 0.12;
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Car>(75, 5, "Petrol"));
    fleet.push_back(make_unique<Bus>(55, 50, "Diesel"));
    fleet.push_back(make_unique<ElectricBike>(22, 1, "Electric"));

    for (auto& vehicle : fleet) {
        vehicle->start();
        cout << "Energy Consumption = " 
             << vehicle->calculateEnergyConsumption() << "\n";
        vehicle->stop();
        cout << "------\n";
    }

    return 0;
}
