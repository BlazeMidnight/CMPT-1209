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
    // Binary opperator == two opperans ex: + (left+right)
    // as a member, the left opperator will be "this->"
    // left one will be the permainter inputted into the function
    Vector2D operator+ (const Vector2D& b);
    Vector2D operator- (const Vector2D& b);
    friend bool operator> (const Vector2D& a, const Vector2D& b);
    friend bool operator>= (const Vector2D& a, const Vector2D& b);
    friend bool operator< (const Vector2D& a, const Vector2D& b);
    friend bool operator<= (const Vector2D& a, const Vector2D& b);
    // Uniary --> incremnt and decrement (ex: ++ or --)
    // Member --> nothing should be pass, as will use "this->"
    Vector2D operator++ ();
    Vector2D operator-- ();
    Vector2D operator++ (int);
    Vector2D operator-- (int);
    // overloading cin and cout
    // Always define as a non-member but a friend
    // a binary opperator
    friend ostream& operator<< (ostream& os, const Vector2D& right); // Const -> not changing the output
    friend istream& operator>> (istream& os, Vector2D& right);
    // What is cin? Reading something from keyboard and storing as x
    // ex: cin >> x;      left >> (binary opperator) right
};

Vector2D::Vector2D() {x = 1; y = 0;}
Vector2D::Vector2D(double a, double b) {x = a; y = b;}

void Vector2D::output() const {cout << "(" << x << "," << y << ")" << endl;}

double Vector2D::getX() const {return x;}
double Vector2D::getY() const {return y;}
void Vector2D::setX(double a) {x = a;}
void Vector2D::setY(double b) {y = b;}

Vector2D Vector2D::operator+ (const Vector2D& b) {
    return Vector2D((this->x + b.x ), (this->y + b.y));
}
Vector2D Vector2D::operator- (const Vector2D& b) {
    return Vector2D((this->x - b.x),(this->y - b.y));
}

bool operator== (const Vector2D& a, const Vector2D& b) {
    return(a.getX() == b.getX() and a.getY() == a.getY());
}
bool operator!= (const Vector2D& a, const Vector2D& b) {
    return(a.getX() != b.getX() or a.getY() != a.getY());
}
bool operator> (const Vector2D& a, const Vector2D& b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) > (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator>= (const Vector2D& a, const Vector2D& b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) >= (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator< (const Vector2D& a, const Vector2D& b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) < (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}
bool operator<= (const Vector2D& a, const Vector2D& b) {
    return (sqrt((a.getX() * a.getX()) + (a.getY() * a.getY()))) <= (sqrt((b.getX() * b.getX()) + (b.getY() * b.getY())));
}


Vector2D Vector2D::operator++()
{
    this->x++;
    return *this;
}
Vector2D Vector2D::operator++(int)
{
    Vector2D temp = *this;
    this->x++;
    return temp;
}
Vector2D Vector2D::operator--()
{
    this->x--;
    return *this;
}
Vector2D Vector2D::operator--(int)
{
    Vector2D temp = *this;
    this->x--;
    return temp;
}


ostream& operator<< (ostream& os, const Vector2D& right) {
    os << "(X = " << right.x << ",\t" << "Y = " << right.y << ")" << endl;
    return os;
}
istream& operator>> (istream& os, Vector2D& right) {
    cout << "X?: ";
    os >> right.x;
    cout << "Y?: ";
    os >> right.y;
    return os;
}



int main() {
    Vector2D a(5, 2), b(2, 5), c;
    /*
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
    */
    cout << a;
}
