// Violation of ISP

#include <iostream>
#include <string>
#include <stdexcept> // For std::logic_error
using namespace std;

// Dummy Document class for illustration
struct Document {};

// "Fat" interface forces all machines to implement unused methods
struct IMachine {
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
    virtual ~IMachine() = default;
};

struct SimplePrinter : IMachine {
    void print(Document& doc) override {
        // actual printing logic
        cout << "SimplePrinter: Printing document." << endl;
    }
    void scan(Document& doc) override {
        // dummy - not supported
        throw logic_error("SimplePrinter: Scan not supported");
    }
    void fax(Document& doc) override {
        // dummy - not supported
        throw logic_error("SimplePrinter: Fax not supported");
    }
};

// Example usage (optional, for testing)
// int main() {
//     SimplePrinter printer;
//     Document doc;
//     printer.print(doc);
//     try {
//         printer.scan(doc);
//     } catch (const std::logic_error& e) {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }