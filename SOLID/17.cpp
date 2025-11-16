// Segregated interfaces for ISP 
// Following ISP keeps our code flexible and implementers happy – each class only signs up for what it can actually do.

// In our notification system, because we anticipated the need to separate concerns, we avoided creating one giant interface.

// Instead, we opted for one role per interface (INotifier for sending a notification via one channel).

// This way, each notifier class has a minimal interface to implement, which it does fully. We don't have unused methods hanging around in our classes.

#include<bits/stdc++.h>
using namespace std;

struct Document{};

// Segregated interfaces
struct IPrinter {
    virtual void print(Document& doc) = 0;
    virtual ~IPrinter() = default;
};

struct IScanner {
    virtual void scan(Document& doc) = 0;
    virtual ~IScanner() = default;
};

struct IFax {
    virtual void fax(Document& doc) = 0;
    virtual ~IFax() = default;
};

// A simple printer now only depends on IPrinter
struct SimplePrinter : IPrinter {
    void print(Document& doc) override {
        // printing logic here
    }
};

// A fax-only device
struct FaxMachine : IFax {
    void fax(Document& doc) override {
        // faxing logic here
    }
};

// A multifunction device can compose or inherit multiple interfaces
struct MultiFunctionPrinter : IPrinter, IScanner, IFax {
    void print(Document& doc) override {
        // print logic
    }
    void scan(Document& doc) override {
        // scan logic
    }
    void fax(Document& doc) override {
        // fax logic
    }
};

int main()
{

return 0;
}