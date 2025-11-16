#include <iostream>

// Define the abstract class Shape
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Define a Circle derived from Shape
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Define a Rectangle derived from Shape
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main() {
    Shape *shape;  // Pointer to Shape
    Circle circle;
    Rectangle rectangle;

    shape = &circle;
    shape->draw();  // Output: "Drawing a circle"

    shape = &rectangle;
    shape->draw();  // Output: "Drawing a rectangle"

    return 0;
}
