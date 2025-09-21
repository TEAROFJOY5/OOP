#include <iostream>
#include <string>
using namespace std;

class MovieShow {
private:
    string showId;
    string movieTitle;
    int screenNo;
    int totalSeats;
    int availableSeats;
public:
    MovieShow(string id = "", string title = "", int screen = 1, int total = 100) {
        showId = id;
        movieTitle = title;
        setScreenNo(screen);
        setTotalSeats(total);
        availableSeats = totalSeats;
    }
    MovieShow(const MovieShow &ms) {
        showId = ms.showId;
        movieTitle = ms.movieTitle;
        screenNo = ms.screenNo;
        totalSeats = ms.totalSeats;
        availableSeats = ms.availableSeats;
    }

    void setShowId(string id) { showId = id; }

    void setTitle(string title) { movieTitle = title; }

    void setScreenNo(int screen) {
        if (screen >= 1 && screen <= 10)
            screenNo = screen;
        else
            screenNo = 1; 
    }

    void setTotalSeats(int seats) {
        if (seats > 0) {
            totalSeats = seats;
            if (availableSeats > seats) availableSeats = seats;  
        }
    }

    string getShowId() { return showId; }
    string getTitle() { return movieTitle; }
    int getScreenNo() { return screenNo; }
    int getTotalSeats() { return totalSeats; }
    int getAvailableSeats() { return availableSeats; }

    void reserve(int n) {
        if (n <= 0) {
            cout << "Invalid reservation amount.\n";
            return;
        }
        if (n <= availableSeats) {
            availableSeats -= n;
            cout << n << " seats reserved successfully.\n";
        } else {
            cout << "Only " << availableSeats << " seats available. Reservation failed.\n";
        }
    }
    void cancel(int n) {
        if (n <= 0) {
            cout << "Invalid cancel amount.\n";
            return;
        }
        if (availableSeats + n <= totalSeats) {
            availableSeats += n;
            cout << n << " seats cancelled successfully.\n";
        } else {
            cout << "Cannot cancel " << n << " seats. It exceeds total seat capacity.\n";
        }
    }

    void printSummary() {
        cout << "\n---- Show Summary ----" << endl;
        cout << "Show ID: " << showId << endl;
        cout << "Movie Title: " << movieTitle << endl;
        cout << "Screen No: " << screenNo << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }
};

int main() {
   
    MovieShow show1("SC-12:30-3D", "The Art of War", 5, 150);

    show1.printSummary();

    show1.reserve(20);

    show1.cancel(5);

    show1.printSummary();

    MovieShow show2 = show1;

    show1.reserve(10);
    
    cout << "\n>> Original Show after more reservations:" << endl;
    show1.printSummary();
    cout << "\n>> Copied Show remains unchanged:" << endl;
    show2.printSummary();
    return 0;
}
