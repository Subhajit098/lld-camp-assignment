#include <iostream>
#include <string>
using namespace std;

// Base Class: Employee
class Employee {
public:
    string name;
    int age;

    Employee(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived Class: Manager
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int a, int ts) : Employee(n, a), teamSize(ts) {}

    void display() {
        cout << "Manager Info:" << endl;
        Employee::display(); // Call base class display
        cout<<"Prints the items in derived class : "<<Employee::name<<endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    Employee e1("Alice", 30);
    Manager m1("Bob", 40, 5);

    e1.display();
    m1.display();

    return 0;
}
