#include <iostream>
#include <string>
using namespace std;

// Class Set Up
class Rational{
private:
    int numer;
    int denom;
public:
    int getNumer() const;
    int getDenom() const;
    void setNumer(int);
    void setDenom(int);
    void input();
    void output() const;
    Rational();
    Rational(int, int = 1);
    void reduce();
};

// Reduce Function
void Rational::reduce() {
    int x = abs(numer);
    int y = abs(denom);
    // find minimum of x and y
    int min = x;
    if (y < x)
        min = y;
    // finding a common factor greater than 1
    int gcf = 1;
    for (int i = 2; i <= min; i++) {
        if (x % i == 0 && y % i == 0){
            gcf = i;
        }
    }
    numer = numer / gcf;
    denom = denom / gcf;
    if (denom < 0){
        numer = -numer;
        denom = -denom;
    }
}

// Cases
Rational::Rational(){
    numer = 0;
    denom = 1;
}
Rational::Rational(int x, int y){
    numer = x;
    if (y != 0)
        denom = y;
    else
        denom = 1;
    reduce();
}

// Setters and Getters
int Rational::getNumer() const {return numer;}
int Rational::getDenom() const {return denom;}
void Rational::setNumer(int x) {
    numer = x;
    reduce();
}
void Rational::setDenom(int x) {
    denom = x;
    if (denom == 0)
        denom = 1;
    reduce();
}

// Input and Output
void Rational::input() {
    cout << "Numerator? ";
    cin >> numer;
    cout << "Denominator? ";
    cin >> denom;
    while (denom == 0)
    {
        cout << "Denominator can't be zero!\n";
        cout << "Denominator? ";
        cin >> denom;
    }
    reduce();
}
void Rational::output() const {
    if (denom != 1)
        cout << numer << "/" << denom << endl;
    else
        cout << numer << endl;
}

// Operators
Rational operator+(const Rational &a, const Rational &b) { // Call by referance
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom() + a.getDenom() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    return c;
}
Rational operator- (const Rational &a, const Rational &b) {
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom() - a.getDenom() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    return c;
}
Rational operator* (const Rational &a, const Rational &b) {
    Rational c;
    c.setNumer(a.getNumer() * b.getNumer());
    c.setDenom(a.getDenom() * b.getDenom());
    return c;
}
Rational operator/ (const Rational &a, const Rational &b) {
    Rational c;
    c.setNumer(a.getNumer() * b.getDenom());
    c.setDenom(a.getDenom() * b.getNumer());
    return c;
}

bool operator< (const Rational &a, const Rational &b) {
    return ((a.getNumer()*b.getDenom() < a.getDenom()*b.getNumer()));
}

bool operator> (const Rational &a, const Rational &b) {
    return (a.getNumer()*b.getDenom() > a.getDenom()*b.getNumer());
}

bool operator<= (const Rational &a, const Rational &b) {
    return (a.getNumer()*b.getDenom() <= a.getDenom()*b.getNumer());
}

bool operator>= (const Rational &a, const Rational &b) {
    return (a.getNumer()*b.getDenom() >= a.getDenom()*b.getNumer());
}

bool operator== (const Rational &a, const Rational &b) {
    return (a.getNumer()*b.getDenom() == a.getDenom()*b.getNumer());
}

bool operator!= (const Rational &a, const Rational &b) {
    return (a.getNumer()*b.getDenom() != a.getDenom()*b.getNumer()); 
}



int main(){
    Rational a, b(5, 5), c(6, 8), d(6, 8);
    a.output();
    b.output();
    c.output();
    d.output();
    if (b>c) {
        cout << "yes!";
        b.output();
        c.output();
    }
    if (c != d) {
        cout << "yest!!";
        c.output();
        d.output();
    } else {
        cout << "No!!";
        c.output();
        d.output();
    }
    //c.output();
    return 0;
}
