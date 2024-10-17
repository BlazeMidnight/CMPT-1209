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
    friend Rational operator+(const Rational &a, const Rational &b); 
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

    /*
    Rational c;
    c.numer = a.numer*b.denom+a.denom*b.denom;
    c.denom = a.denom + b.denom; 
    c.reduce;
    return c; 

    */
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


Rational operator+= (Rational &a, const Rational &b) {
    a = a + b;
    return a;
}

Rational operator-= (Rational &a, const Rational &b) {
    a = a - b;
    return a;
}
Rational operator*= (Rational &a, const Rational &b) {
    a = a * b;
    return a;
}
Rational operator/= (Rational &a, const Rational &b) {
    a = a / b;
    return a;
}

Rational operator++ (Rational & a) { //Prefix only ex: ++a
    a.setNumer(a.getNumer + a.getDenom());
    return a;
}

Rational operator++ (Rational & a, int) { // int = dummy var; Postfix only 
    Rational temp = a;
    temp.setNumer(a.getNumer + a.getDenom());
    return temp;
}



int main(){
    Rational a(1, 4), c(1, 4), d(1, 4), e(1, 4), b(2, 3);
    a += b;
    a.output();
    c -= b;
    c.output();
    d *= b;
    d.output();
    e /= b;
    e.output();


    return 0;
}
