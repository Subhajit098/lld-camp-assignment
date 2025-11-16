#include <iostream>
#include <string>
using namespace std;

// Abstract Class: Payment
class Payment {
public:
    virtual void makePayment(float amount) = 0; // Pure virtual function
};

// CreditCard Payment
class CreditCard : public Payment {
public:
    void makePayment(float amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

// DigitalWallet Payment
class DigitalWallet : public Payment {
public:
    void makePayment(float amount) override {
        cout << "Paid " << amount << " using Digital Wallet." << endl;
    }
};

void executePayment(Payment* paymentMethod, float amount) {
    paymentMethod->makePayment(amount);
}

int main() {
    Payment* payment;

    CreditCard cc;
    DigitalWallet dw;

    payment = &cc;
    executePayment(payment, 50.0);  // Output: "Paid 50 using Credit Card."

    payment = &dw;
    executePayment(payment, 25.0);  // Output: "Paid 25 using Digital Wallet."

    return 0;
}
