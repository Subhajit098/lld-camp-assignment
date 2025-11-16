#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FileManager {
public:
    string fileName;
    vector<string> data;

    FileManager(const string& fileName) : fileName(fileName) {}

    void read() {
        cout << "Reading file " << fileName << endl;
        // File reading logic here
    }

    void write() {
        cout << "Writing to file " << fileName << endl;
        // File writing logic here
    }

    void processCSV() {
        cout << "Processing CSV file " << fileName << endl;
        // CSV processing logic
    }

    void processJSON() {
        cout << "Processing JSON file " << fileName << endl;
        // JSON processing logic
    }
};

void handleFiles(FileManager* fm) {
    fm->read();
    fm->processCSV();  // ⚠️ Violates Liskov Substitution Principle
    fm->write();
}

int main() {
    FileManager fm("example.csv");
    handleFiles(&fm);

    return 0;
}
