#include<bits/stdc++.h>
using namespace std;

class FileManager {
public:
    std::string fileName;
    std::vector<std::string> data;

    FileManager(const std::string& fileName) : fileName(fileName) {}

    void read() {
        std::cout << "Reading file " << fileName << std::endl;
        // File reading logic here
    }

    void write() {
        std::cout << "Writing to file " << fileName << std::endl;
        // File writing logic here
    }

    void processCSV() {
        std::cout << "Processing CSV file " << fileName << std::endl;
        // CSV processing logic
    }

    void processJSON() {
        std::cout << "Processing JSON file " << fileName << std::endl;
        // JSON processing logic
    }
};

void handleFiles(FileManager* fm) {
    fm->read();
    fm->processCSV(); // Violates Liskov Substitution Principle
    fm->write();
}

int main() {
    FileManager fm("example.csv");
    handleFiles(&fm);

    return 0;
}