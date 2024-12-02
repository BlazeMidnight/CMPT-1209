#include <iostream>
#include <vector>
using namespace std;

class Passenger {
private:
    string name;
    double fare;
    int points;

public:
    Passenger(string n = "", double f = 0.0, int p = 0) : name(n), fare(f), points(p) {}

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter fare: ";
        cin >> fare;
        cout << "Enter points: ";
        cin >> points;
    }

    void output() const {
        cout << name << " - Fare: " << fare << ", Points: " << points << endl;
    }

    double priority() const {
        return (fare * 0.5) + (points * 0.5);
    }

    // Comparison function for sorting
    bool operator<(const Passenger &other) const {
        return this->priority() < other.priority();
    }
};

class Flight {
private:
    string flightNumber;
    vector<Passenger> passengers;

    // Custom bubble sort to sort passengers
    void sortPassengers() {
        int n = passengers.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (passengers[j + 1] < passengers[j]) {
                    // Swap passengers[j] and passengers[j + 1]
                    Passenger temp = passengers[j];
                    passengers[j] = passengers[j + 1];
                    passengers[j + 1] = temp;
                }
            }
        }
    }

public:
    Flight(string fn = "") : flightNumber(fn) {}

    void insert(const Passenger &p) {
        passengers.push_back(p);
        sortPassengers(); // Sort after adding a new passenger
    }

    void display() const {
        for (const auto &p : passengers) {
            p.output();
        }
    }

    void leave() {
        if (!passengers.empty()) {
            passengers.erase(passengers.begin());
        } else {
            cout << "No passengers to remove.\n";
        }
    }
};

int main() {
    Flight flight("AA123");
    Passenger p;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for passenger " << i + 1 << ":\n";
        p.input();
        flight.insert(p);
    }

    cout << "\nPassenger list:\n";
    flight.display();

    flight.leave();
    cout << "\nAfter removing one passenger:\n";
    flight.display();

    flight.leave();
    cout << "\nAfter removing another passenger:\n";
    flight.display();

    return 0;
}
