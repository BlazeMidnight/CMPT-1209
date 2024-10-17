#include <iostream>
#include <algorithm> 
using namespace std;

class rational {
private:
    int numerator;
    int denominator;
public:
    int getNumberator();
    int getDenominator();
    void setNumberator(int);
    void setDenominator(int);
    void input();
    void output();
    rational();
    rational(int, int = 1);
    void reduce(); 

};

void rational::reduce() {
    int x = abs(numerator);
    int y = abs(denominator);
    int gcf = 0; 
    bool s = false; 
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
        s = true;
    }

    for (int i = 1; i <= x; i++) {
        if (y % i == 0 && x % i == 0) {
            gcf = i; 
        }
    }
   
    if (s == true) {
        numerator = y / gcf;
        denominator = x / gcf;
    }
    else {
        numerator = x / gcf;
        denominator = y / gcf;
    }
}

void rational::input() {
    cout << "Enter the number for the numerator: ";
    cin >> numerator;
    cout << "Enter the number for the denominator: ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "The denominator can't be zero, please enter another number: ";
    }
}
void rational::output() {
    if (numerator < 0 && denominator > 0) {
        cout << "The rational number is stored as: -" << abs(numerator) << "/" << denominator << endl; 
    }
    else if (numerator > 0 && denominator < 0) {
        cout << "The rational number is stored as: -" << numerator << "/" << abs(denominator) << endl;
    }
    else if (numerator < 0 && denominator < 0){
        cout << "The rational number is stored as: " << abs(numerator) << "/" << abs(denominator) << endl;
    }
    else {
        cout << "The rational number is stored as: " << numerator << "/" << denominator << endl;
    }
}

rational::rational(int a, int b) {
    numerator = a; 
    denominator = b;
}


rational::rational() {
    numerator = 0;
    denominator = 1;  
}


int rational::getNumberator() {
    return numerator;
}
int rational::getDenominator() {
    return denominator;
}
void rational::setNumberator(int n) {
    numerator = n;
}
void rational::setDenominator(int d) {
    if (d == 0){
        denominator = 0; 
    }
    else {
        denominator = d;
    }
}


int main() {
    rational a, b(6), c(-6, -8), d(9, -6); 
    a.output();   
    b.output();
    c.reduce();
    c.output();
    d.reduce(); 
    d.output(); 

    return 0;
}
