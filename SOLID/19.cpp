// What’s wrong here?

// DataProcessor (the high-level module) directly depends on MySQLDatabase (the low-level module).

// If tomorrow we switch to MongoDB or PostgreSQL,
// we have to edit DataProcessor code.

// That’s tight coupling.
// Our code becomes hard to extend and hard to test (because we can’t easily replace the database).

#include<bits/stdc++.h>
using namespace std;

class MySQLDatabase {
public:
    void saveData(string data) {
        cout << "Saving data in MySQL: " << data << endl;
    }
};

class DataProcessor {
public:
    void process() {
        MySQLDatabase db; // tightly coupled!
        db.saveData("User data");
    }
};


int main()
{

return 0;
}