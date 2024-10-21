#include <iostream>
#include <string>
using namespace std;

class NumDays {
private:
    double hours;
public:
    NumDays();
    NumDays(double);
    double getHours() const;
    double getDays() const;
    void setHours(double);
    friend NumDays operator- (const NumDays &a, const NumDays &b);
    NumDays operator-- ();
    NumDays operator-- (int);
    friend ostream& operator<< (ostream& os, const NumDays& right);
    friend istream& operator>> (istream& is, NumDays& right);

};

NumDays::NumDays() {
    hours = 0;
}

NumDays::NumDays(double h) {
    hours = h;
}

double NumDays::getHours() const {return hours;}
double NumDays::getDays() const {return hours/8;}
void NumDays::setHours(double h) {hours = h;}

NumDays operator+ (const NumDays &a, const NumDays &b) {
    return (a.getHours() + b.getHours());
}

NumDays operator- (const NumDays &a, const NumDays &b) {
    return (a.hours - b.hours);
}


NumDays operator++ (NumDays &a) {
    a.setHours(a.getHours()+ 1);
    return (a);
}

NumDays operator++ (NumDays &a, int) {
    NumDays temp = a;
    a.setHours(a.getHours() + 1);
    return temp;
}


NumDays NumDays::operator-- () {
    this->hours--;
    return *this;
}


NumDays NumDays::operator-- (int) {
    NumDays temp = *this;
    this->hours--;
    return temp;
}

ostream& operator<< (ostream& os, const NumDays& right) {
    os << "Hour: " << right.hours << "\tDays: " << right.hours/8;
    return os;
};

istream& operator>> (istream& is, NumDays& right) {
    cout << "How many hours worked?: ";
    is >> right.hours;
    return is;
}

int main() {
    NumDays a(18), b(12), c, d;
    cout << a << endl;
    cout << b << endl;

    c = a + b;

    // Display three.
    cout << c << endl;

    // Postfix increment...
    d = c++;
    cout << d << endl;

    // Prefix increment...
    d = ++c;
    cout << d << endl;

    // Postfix decrement...
    d = c--;
    cout << d << endl;

    // Prefix increment...
    d = --c;
    cout << d << endl;
    return 0;
}
