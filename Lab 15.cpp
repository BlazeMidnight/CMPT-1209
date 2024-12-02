// Pure Virtual functions
// No general formula for some things (ex: area of a shape, diff shape have diff fomulas for shapes)
// Function that is mentioned but not defined
// ex: Virtual void ear() = 0;


#include <iostream>
using namespace std;

class Shape {
protected:
    double area;
public:
    double getArea() const {return area;}
    virtual void calcArea() = 0;
};

class Circle : public Shape {
private:
    long int centerX;
    long int centerY;
    double radius;
public:
    Circle(long int x, long int y, double r) {
        centerX = x;
        centerY = y;
        radius = r;
    }
    long int getCenterX() {return centerX;}
    long int getCenterY() {return centerY;}
    void calcArea() {
        area = 3.14159 * radius * radius;
    }
    
};

class Rectangle : public Shape {
private:
    long int width;
    long int length;
public:
    Rectangle(long int w, long int l) {
        width = w;
        length = l;
    }
    long int getWidth() {return width; }
    long int getLength() {return length; }
    void calcArea() {
        area =  length * width;
    }
};

int main() {
    Circle* a = new Circle(5, 2, 3);
    Rectangle* b = new Rectangle(2, 4);
    a->calcArea();
    b->calcArea();
    cout << a->getArea() << endl;
    cout << b->getArea() << endl;
    
    delete a;
    delete b;
    
    return 0;
}
