#include <iostream>
using namespace std;

// Base Class: Shape
class Shape {
public:
    virtual double area() { return 0; } // Virtual function
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }
};

void printArea(Shape* shape) {
    cout << "Area: " << shape->area() << endl;
}

int main() {
    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    printArea(&c); // Output: Area: 78.5397
    printArea(&r); // Output: Area: 24

    return 0;
}
