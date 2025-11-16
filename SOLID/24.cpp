#include <iostream>
#include <string>
using namespace std;

class Invoice {
public:
    double total = 0.0;
    string customerEmail;

    void addItem(const string &name, double price) {
        total += price;
    }

    double applyDiscount(const string &coupon) {
        if (coupon == "NEW50") return total * 0.5;
        if (coupon == "FEST10") return total * 0.9;
        return total;
    }

    void saveToDb() {
        cout << "INSERT INTO invoices ..." << endl;
    }

    void sendEmail() {
        cout << "Sending email to " << customerEmail << endl;
    }
};
