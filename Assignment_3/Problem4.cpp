#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

class Booking {
public:
    int bookingID;
    string name;
    int roomNo;
    double bill;

    Booking() {
        bookingID = 0;
        name = "";
        roomNo = 0;
        bill = 0.0;
    }

    Booking(int id, string n, int r, double b) : bookingID(id), name(n), roomNo(r), bill(b) {}

    void inputDetails() {
        cout << "Enter Booking ID: ";
        while (!(cin >> bookingID)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter numeric Booking ID: ";
        }
        cin.ignore(); // ignore leftover newline

        cout << "Enter Guest Name: ";
        getline(cin, name);

        cout << "Enter Room Number: ";
        while (!(cin >> roomNo)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter numeric Room Number: ";
        }

        cout << "Enter Total Bill: ";
        while (!(cin >> bill)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter numeric Bill: ";
        }
        cin.ignore();
    }

    void display() const {
        cout << left << setw(10) << bookingID
             << setw(20) << name
             << setw(10) << roomNo
             << setw(10) << fixed << setprecision(2) << bill << endl;
    }
};

// Part B - Create and save bookings to file
void createFile() {
    ofstream fout;
    try {
        fout.open("hotel.txt", ios::binary | ios::app);
        if (!fout) throw runtime_error("Cannot create file hotel.txt");

        int n;
        cout << "How many bookings to enter? ";
        while (!(cin >> n) || n <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter positive number: ";
        }
        cin.ignore();

        for (int i = 0; i < n; i++) {
            Booking b;
            cout << "\nEnter details for Booking " << i + 1 << ":\n";
            b.inputDetails();
            fout.write(reinterpret_cast<char*>(&b), sizeof(b));
            cout << "Booking saved.\n";
        }

        fout.close();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Part C - Display all records
void displayRecords() {
    ifstream fin;
    try {
        fin.open("hotel.txt", ios::binary);
        if (!fin) throw runtime_error("File hotel.txt not found");

        Booking b;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Room" << setw(10) << "Bill" << endl;
        cout << "------------------------------------------------------\n";
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            b.display();
        }

        fin.close();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Part D - Search a booking by ID
void searchRecord() {
    int id;
    cout << "Enter Booking ID to search: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter numeric Booking ID: ";
    }

    ifstream fin;
    try {
        fin.open("hotel.txt", ios::binary);
        if (!fin) throw runtime_error("File hotel.txt not found");

        Booking b;
        bool found = false;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            if (b.bookingID == id) {
                cout << "Booking found:\n";
                cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Room" << setw(10) << "Bill" << endl;
                cout << "------------------------------------------------------\n";
                b.display();
                found = true;
                break;
            }
        }
        if (!found) throw runtime_error("Booking not found.");
        fin.close();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Part E - Update bill of a booking
void updateBill() {
    int id;
    cout << "Enter Booking ID to update bill: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter numeric Booking ID: ";
    }

    fstream fio;
    try {
        fio.open("hotel.txt", ios::binary | ios::in | ios::out);
        if (!fio) throw runtime_error("File hotel.txt not found");

        Booking b;
        bool found = false;
        while (fio.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            if (b.bookingID == id) {
                found = true;
                cout << "Current bill: " << b.bill << endl;
                double newBill;
                cout << "Enter new bill amount: ";
                while (!(cin >> newBill)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Enter numeric bill: ";
                }

                b.bill = newBill;
                fio.seekp(-static_cast<int>(sizeof(b)), ios::cur);
                fio.write(reinterpret_cast<char*>(&b), sizeof(b));
                cout << "Bill updated successfully.\n";
                break;
            }
        }

        if (!found) throw runtime_error("Booking ID not found.");
        fio.close();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nGrandView Hotel Booking System\n";
        cout << "1. Create Bookings\n2. Display All Bookings\n3. Search Booking\n4. Update Bill\n5. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter numeric choice: ";
        }

        switch (choice) {
            case 1: createFile(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateBill(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
