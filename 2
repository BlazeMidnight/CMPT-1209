#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class rational {
private:
    int numerator;
    int denominator;
public:
    int getNumerator();
    int getDenominator();
    void setNumerator(int);
    void setDenominator(int);
    void input();
    void output();
    rational();
    rational(int, int = 1);
    void reduce();
};

void rational::reduce() {
    int gcf = gcd(numerator, denominator);
    numerator /= gcf;
    denominator /= gcf;
    
    // Ensure denominator is positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void rational::input() {
    cout << "Enter the number for the numerator: ";
    cin >> numerator;
    cout << "Enter the number for the denominator: ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "The denominator can't be zero, please enter another number: ";
        cin >> denominator;
    }
}

void rational::output() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    cout << "The rational number is stored as: " << numerator << "/" << denominator << endl;
}

rational::rational(int a, int b) {
    numerator = a;
    denominator = b;
    reduce();
}

rational::rational() {
    numerator = 0;
    denominator = 1;
    reduce();
}

int rational::getNumerator() {return numerator;}
int rational::getDenominator() {return denominator;}
void rational::setNumerator(int n) {numerator = n;}
void rational::setDenominator(int d) {
    if (d == 0) {
        cout << "Error: Denominator can't be zero, setting it to 1." << endl;
        denominator = 1;
    } else {
        denominator = d;
    }
}

int main() {
    rational a, b(6), c(-6, -8), d(9, -6), e;
    //cout << "================================" << endl;
    a.output();
    b.output();
    c.output();
    d.output();
    /*
    cout << "================================" << endl;
    e.input();
    e.output();
    cout << "================================" << endl;
    */
    return 0;
}
