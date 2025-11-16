#include<bits/stdc++.h>
using namespace std;

class AddItem{
    virtual void addItem(const string &name,double price)=0;
};

class IApplyDiscount{
public:
    virtual double discount(double total)=0;
};

class Apply50: public IApplyDiscount{
public:
    double discount(double total) override{
        return 0.5*total;
    }
};

class Apply10: public IApplyDiscount{
public:
    double discount(double total) override{
        return 0.9*total;
    }
};

class Invoice {
public:
    double total = 0.0;
    string customerEmail;

    void addItem(const string &name, double price) {
        total += price;
    }
};

class ISave{
    public:
        virtual void save(const Invoice &invoice)=0;
};

class SaveToDb : public ISave{
    public:
        void save(const Invoice& invoice) override{
            cout<<"Saving to invoices : "<<invoice.total<<endl;
        }
};

class EmailService{
    public:
        void sendEmail(const Invoice &invoice){
            cout<<"Sending emails to : "<<invoice.customerEmail<<endl;
        }
};

int main()
{

return 0;
}