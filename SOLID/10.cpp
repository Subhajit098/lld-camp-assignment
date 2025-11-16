#include<bits/stdc++.h>
using namespace std;

class Rectangle {
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }

    int getArea() const { return width * height; }

protected:
    int width, height;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override {
        width = height = w; // keeps sides equal
    }
    void setHeight(int h) override {
        width = height = h; // keeps sides equal
    }
};

void process(Rectangle& r) {
    r.setWidth(10);
    r.setHeight(5);
    cout << r.getArea(); // Expected 50
}




int main()
{
    Square s;
    process(s); // Outputs 25! 😱
return 0;
}