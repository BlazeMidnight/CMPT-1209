#include <iostream>
#include <string>
#include <stdexcept> // For logic_error
using namespace std;

class RationalException : public logic_error {
public:
    RationalException()
    :logic_error("Denominator cannot be zero.") {}
};

class Rational {
private:
    int numer;
    int denom;

public:
    // Constructors
    Rational();
    Rational(int, int);

    // Getters
    int getNumer() const;
    int getDenom() const;

    // Setters
    void setNumer(int);
    void setDenom(int);

    // Methods
    void input();
    void output() const;
    void reduce();


    Rational friend operator+(const Rational& a, const Rational& b);
};



void Rational::reduce() {
    int x = abs(numer);
    int y = abs(denom);
    int min = (x < y) ? x : y;

    int gcf = 1;
    for (int i = 2; i <= min; ++i) {
        if (x % i == 0 && y % i == 0) {
            gcf = i;
        }
    }

    numer /= gcf;
    denom /= gcf;

    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
}

Rational::Rational() : numer(0), denom(1) {}

Rational::Rational(int x, int y) : numer(x) {
    if (y == 0) {
        throw RationalException();
    }
    denom = y;
    reduce();
}

int Rational::getNumer() const {
    return numer;
}

int Rational::getDenom() const {
    return denom;
}

void Rational::setNumer(int x) {
    numer = x;
    reduce();
}

void Rational::setDenom(int x) {
    if (x == 0) {
        throw RationalException();
    }
    denom = x;
    reduce();
}

void Rational::input() {
    cout << "Numerator? ";
    cin >> numer;
    cout << "Denominator? ";
    cin >> denom;

    if (denom == 0) {
        throw RationalException();
    }

    reduce();
}

void Rational::output() const {
    if (denom != 1) {
        cout << numer << "/" << denom << endl;
    } else {
        cout << numer << endl;
    }
}

Rational operator+(const Rational &a, const Rational &b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom() + a.getDenom() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    return c;
}
Rational operator-(const Rational& a, const Rational& b)
{
    int x = a.getNumer() * b.getDenom() - a.getDenom() * b.getNumer();
    int y = a.getDenom() * b.getDenom();
    return Rational(x,y);
}
Rational operator*(const Rational& a, const Rational& b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    return c;
}
Rational operator/(const Rational& a, const Rational& b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom());
    c.setDenom(a.getDenom() * b.getNumer());
    return c;
}
void operator+=(Rational& a, const Rational& b)
{
    a = a + b;
}
void operator-=(Rational& a, const Rational& b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom() - a.getDenom() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    a = c;
}
void operator*=(Rational& a, const Rational& b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    a = c;
}
void operator/=(Rational& a, const Rational& b)
{
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom());
    c.setDenom(a.getDenom() * b.getNumer());
    a = c;
}
bool operator<(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) < (a.getDenom() * b.getNumer());
}
bool operator<=(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) <= (a.getDenom() * b.getNumer());
}
bool operator>(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) > (a.getDenom() * b.getNumer());
}
bool operator>=(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) >= (a.getDenom() * b.getNumer());
}
bool operator==(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) == (a.getDenom() * b.getNumer());
}
bool operator!=(const Rational& a, const Rational& b)
{
    return (a.getNumer() * b.getDenom()) != (a.getDenom() * b.getNumer());
}

// Main Function
int main() {
    try {
        Rational a(1, 7), b(1, 0);
        a += b;
        a.output();
        b.output();
    } catch (const RationalException& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
