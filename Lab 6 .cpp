#include <iostream>
#include <string>
using namespace std;

class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D();
    Vector2D(double, double);
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void output() const;
    Vector2D operator+ (const Vector2D b);
    Vector2D operator- (const Vector2D b);
    friend bool operator> (const Vector2D a, const Vector2D b);
    friend bool operator>= (const Vector2D a, const Vector2D b);
    friend bool operator< (const Vector2D a, const Vector2D b);
    friend bool operator<= (const Vector2D a, const Vector2D b);
    Vector2D operator++ ();
    Vector2D operator-- ();
    Vector2D operator++ (int);
    Vector2D operator-- (int);
    
};

Vector2D::Vector2D() {x = 0; y = 0;}
Vector2D::Vector2D(double a, double b) {x = a; y = b;}

void Vector2D::output() const {cout << "(" << x << "," << y << ")" << endl;}

double Vector2D::getX() const {return x;}
double Vector2D::getY() const {return y;}
void Vector2D::setX(double a) {x = a;}
void Vector2D::setY(double b) {y = b;}

Vector2D Vector2D::operator+ (const Vector2D b) {return Vector2D((this->getX() + b.getX()),(this->getY() + b.getY()));}
Vector2D Vector2D::operator- (const Vector2D b) {return Vector2D((this->getX() - b.getX()),(this->getY() - b.getY()));}

bool operator== (const Vector2D a, const Vector2D b) {return(a.getX() == b.getX() and a.getY() == a.getY());}
bool operator!= (const Vector2D a, const Vector2D b) {return(a.getX() != b.getX() or a.getY() != a.getY());}
bool operator> (const Vector2D a, const Vector2D b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) > (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator>= (const Vector2D a, const Vector2D b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) >= (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator< (const Vector2D a, const Vector2D b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) < (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator<= (const Vector2D a, const Vector2D b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) <= (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}


Vector2D Vector2D::operator++ () {
    ++x;
    ++y;
    return *this;
}

Vector2D Vector2D::operator-- () {
    --x;
    --y;
    return *this;
}

Vector2D Vector2D::operator++ (int) {
    Vector2D temp = *this;
    ++x;
    ++y;
    return temp;
}

Vector2D Vector2D::operator-- (int) {
    Vector2D temp = *this;
    --x;
    --y;
    return temp;
}



int main() {
    Vector2D a(5, 2), b(2, 5), c;
    a.output();
    b.output();
    c = a + b;
    c.output();
    c = a - b;
    c.output();
    c++.output();
    ++c;
    c.output();
    return 0;
}
