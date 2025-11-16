#include<bits/stdc++.h>
using namespace std;

class Bird {
public:
    virtual void fly() { cout << "Bird is flying"; }
};

class Penguin : public Bird {
public:
    void fly() override { throw runtime_error("Penguins can't fly!"); }
};


// fix 
class Bird {
public:
    virtual void eat() = 0;
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void eat() override {}
    void fly() override {}
};

class Penguin : public Bird {
public:
    void eat() override {}
    // no fly(), because penguins don’t fly
};


int main()
{

return 0;
}