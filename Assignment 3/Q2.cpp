#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;
    int getDaysInMonth(int month) const {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
            return 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        else // February
            return 28;
    }

public:
    // Default constructor
    Date() {
        month = 1;
        day = 1;
        year = 2000;
    }

    // Accessor functions
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Mutator functions
    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else {
            cout << "Invalid month. Setting to January.\n";
            month = 1;
        }
    }

    void setDay(int d) {
        if (d >= 1 && d <= getDaysInMonth(month)) 
            day = d;
        else {
            cout << "Invalid day. Setting to 1.\n";
            day = 1;
        }
    }

    void setYear(int y) { year = y; }

    // Input function
    void inputDate() {
        int m, d, y;
        cout << "Enter month (1-12): ";
        cin >> m;
        setMonth(m);

        cout << "Enter day: ";
        cin >> d;
        setDay(d);

        cout << "Enter year: ";
        cin >> y;
        setYear(y);
    }

    // Output functions
    void output1() const { cout << month << "/" << day << "/" << year << endl; }
    void output2() const {
        static const string months[] = {"January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }
    void output3() const {
        static const string months[] = {"January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
        cout << day << " " << months[month - 1] << " " << year << endl;
    }


    void increment() {
        if (day == getDaysInMonth(month)) {
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            } else {
                month++;
            }
        } else {
            day++;
        }
    }


    void decrement() {
        if (day == 1) {
            if (month == 1) {
                month = 12;
                year--;
                day = 31;
            } else {
                month--;
                day = getDaysInMonth(month);
            }
        } else {
            day--;
        }
    }
};

int main() {
    Date date; // Default date is January 1, 2000
    date.output1();
    date.output2();
    date.output3();

    cout << "\nEnter a new date:\n";
    date.inputDate();

    cout << "\nDate in different formats:\n";
    date.output1();
    date.output2();
    date.output3();

    cout << "\nIncrementing the date:\n";
    date.increment();
    date.output1();

    cout << "\nDecrementing the date:\n";
    date.decrement();
    date.output1();

    return 0;
}
