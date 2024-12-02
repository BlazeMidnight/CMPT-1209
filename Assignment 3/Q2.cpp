#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;

    int daysInMonth(int month) const {
        if (month == 2) return 28;
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        return 31;
    }

public:
    Date() : month(1), day(1), year(2000) {}

    void input() {
        do {
            cout << "Enter month (1-12): ";
            cin >> month;
        } while (month < 1 || month > 12);

        do {
            cout << "Enter day (1-" << daysInMonth(month) << "): ";
            cin >> day;
        } while (day < 1 || day > daysInMonth(month));

        cout << "Enter year: ";
        cin >> year;
    }

    void output1() const { cout << month << "/" << day << "/" << year << endl; }
    void output2() const { /* Implement month name */ }
    void output3() const { /* Implement day first format */ }

    void increment() { /* Handle month/year rollover */ }
    void decrement() { /* Handle month/year rollback */ }
};

int main() {
    Date date;
    date.input();
    date.output1();
    date.increment();
    date.output1();
    date.decrement();
    date.output1();

    return 0;
}
