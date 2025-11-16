// Flexible:
// We can easily switch databases — no change in DataProcessor.

// Testable:
// We can create a fake MockDatabase for testing without needing a real one.

// Extensible:
// New database? Just implement Database interface — no code changes elsewhere.

// Stable abstraction:
// The DataProcessor doesn’t care how the data is saved — just that it can be saved.
#include<bits/stdc++.h>
using namespace std;

class Database {
public:
    virtual void saveData(string data) = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void saveData(string data) override {
        cout << "Saving data in MySQL: " << data << endl;
    }
};

class MongoDBDatabase : public Database {
public:
    void saveData(string data) override {
        cout << "Saving data in MongoDB: " << data << endl;
    }
};

class DataProcessor {
    Database* db;
public:
    DataProcessor(Database* database) : db(database) {}

    void process() {
        db->saveData("User data");
    }
};


int main()
{
    MySQLDatabase mysql;
    DataProcessor dp1(&mysql);
    dp1.process();

    MongoDBDatabase mongo;
    DataProcessor dp2(&mongo);
    dp2.process();
return 0;
}

