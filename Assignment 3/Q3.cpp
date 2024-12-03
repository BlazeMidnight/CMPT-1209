#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

class Passenger {
private:
    string name;
    double fare;
    int points;

public:
    Passenger(string n = "", double f = 0.0, int p = 0) : name(n), fare(f), points(p) {}

    void input() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter name: ";
        getline(cin, name);
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
        long int n = passengers.size();
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

// Customer structure
struct Customer {
    double fare;
    int points;
    string name;

    Customer(double f, int p, string n) : fare(f), points(p), name(n) {}
};

// Function to print the queue
void printQueue(queue<Customer> q) {
    cout << "Queue is :" << endl;
    cout << setw(10) << "Fare" << setw(10) << "Points" << setw(15) << "Name" << endl;
    cout << "-----------------------------------" << endl;

    while (!q.empty()) {
        Customer c = q.front();
        cout << setw(10) << fixed << setprecision(2) << c.fare
             << setw(10) << c.points
             << setw(15) << c.name << endl;
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<Customer> q;

    // Adding customers to the queue
    q.push(Customer(490.28, 220, "Terry"));
    q.push(Customer(480.12, 245, "John"));
    q.push(Customer(698.95, 100, "Alex"));
    q.push(Customer(577.21, 311, "Susan"));
    q.push(Customer(590.08, 414, "Brian"));

    // Initial queue
    printQueue(q);

    // Removing the first customer
    cout << "Customer who leaves is: " << q.front().name << endl;
    q.pop();
    printQueue(q);

    // Removing the next customer
    cout << "Customer who leaves is: " << q.front().name << endl;
    q.pop();
    printQueue(q);

    return 0;
}
