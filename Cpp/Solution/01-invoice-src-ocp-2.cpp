// 01-invoice-srp-ocp.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

struct LineItem {
    string sku;
    int quantity{0};
    double unitPrice{0.0};
};

class IDiscount{
    public:
        virtual double calculateDiscount(const map<string, double>& discounts)=0;
};

class FlatOff:public IDiscount{
    public:
        double calculateDiscount(const map<string, double>& discounts) override{
            double price=0.0;
            for (auto& kv : discounts) {
                const string& k = kv.first;
                double v = kv.second;
                 if (k == "flat_off") {
                    price += v;
                } 
            }
            return price;
        } 
};

class PercentOff:public IDiscount{
    private:
        double subtotal;
    public:
        PercentOff(const double &sub) : subtotal(sub) {}
        double calculateDiscount(const map<string, double>& discounts) override{
            double price=0.0;
            for (auto& kv : discounts) {
                const string& k = kv.first;
                double v = kv.second;
                if (k == "percent_off") {
                    price += subtotal * (v / 100.0);
                } 
            }
            return price;
        } 
};

class ICalculateSubTotal{
    public: 
        virtual double calculateSubTotal(const vector<LineItem>& items) =0;
};

class CalculateSubTotal :public ICalculateSubTotal{
    public:
    double calculateSubTotal(const vector<LineItem>& items) override{
        double subtotal = 0.0;
        for (auto& it : items) subtotal += it.unitPrice * it.quantity;
        return subtotal;
    }
};

class CalculateTax{
    private: 
        double subtotal;
        double discountTotal;
    public:
        CalculateTax(double sub,double discount) : subtotal(sub), discountTotal(discount) {}
        double taxCalculator() {
            return (subtotal-discountTotal)*0.18;
        }
};

class CalculateGrand{
    private: 
        double subtotal;
        double discountTotal;
        double tax;
    public:
        CalculateGrand(double sub,double discount,double t) : subtotal(sub), discountTotal(discount), tax(t) {}
        double taxCalculator() {
            return subtotal-discountTotal+tax;
        }
};

class IPrintInvoice{
    protected:
        double subtotal,discount,tax,grand;
    public:
        IPrintInvoice(double subtotal,double discount,double tax,double grand) : 
        subtotal(subtotal),discount(discount),tax(tax),grand(grand) {}
        virtual string print(const vector<LineItem> &items,const map<string, double>& discounts,const string &email) = 0;
};

class PrintInvoice:public IPrintInvoice{
    public:
        string print(const vector<LineItem> &items,const map<string, double>& discounts,const string &email) override{
            ostringstream pdf;
            pdf << "INVOICE\n";
            for (auto& it : items) {
                pdf << it.sku << " x" << it.quantity << " @ " << it.unitPrice << "\n";
            }
            pdf << "Subtotal: " << subtotal << "\n"
                << "Discounts: " << discount << "\n"
                << "Tax: " << tax << "\n"
                << "Total: " << grand << "\n";

            // email I/O inline (tight coupling)
            if (!email.empty()) {
                cout << "[SMTP] Sending invoice to " << email << "...\n";
            }

            // logging inline
            cout << "[LOG] Invoice processed for " << email << " total=" << grand << "\n";

            return pdf.str();
        }
};

class Compute{
    public:
        //! Give this constructro the value required.
        PrintInvoice invoice;
        Compute(PrintInvoice &i) : invoice(i) {}
        double compute(vector<LineItem>& items,map<string, double>& discounts){
            string dummyEmail = "noreply@example.com";
            auto rendered = invoice.print(items, discounts, dummyEmail);
            auto pos = rendered.rfind("Total:");
            if (pos == string::npos) throw runtime_error("No total");
            auto line = rendered.substr(pos + 6);
            return stod(line);
        }
};

int main() {
    vector<LineItem> items = { {"ITEM-001", 3, 100.0}, {"ITEM-002", 1, 250.0} };
    map<string,double> discounts = { {"percent_off", 10.0} };
    CalculateSubTotal CsubTotal;
    double subtotal=CsubTotal.calculateSubTotal(items);


    FlatOff CflatOff;
    double flatOff=CflatOff.calculateDiscount(discounts);
    PercentOff CperCentOff(subtotal);
    double percentOff=CperCentOff.calculateDiscount(discounts);
    double discount=percentOff+flatOff;


    CalculateTax CalTax(subtotal,discount);
    double tax=CalTax.taxCalculator();

    CalculateGrand CalGrand(subtotal,discount,tax);
    double grand=CalGrand.taxCalculator();

    PrintInvoice invoice(subtotal,discount,tax,grand);
    cout<<invoice.print(items,discounts,"customer@example.com");

    return 0;
}
