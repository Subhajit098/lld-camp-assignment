class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() const override { return width * height; }

private:
    int width, height;
};

class Square : public Shape {
public:
    Square(int side) : side(side) {}
    int getArea() const override { return side * side; }

private:
    int side;
};
