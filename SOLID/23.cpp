#include<bits/stdc++.h>
using namespace std;

class IFileHandler{
    public:
        virtual void read(const string &filename)=0;
        virtual void write(const string &filename)=0;
        virtual ~IFileHandler()=default;
};

class IFileProcessor{
    public:
        virtual void process(const string &filename)=0;
        virtual ~IFileProcessor()=default;
};

class FileHandler:public IFileHandler{
    public:
        void read(const string &filename) override{
            cout<<"Reading file name : "<<filename<<endl;
        }
        void write(const string &filename) override{
            cout<<"Writing file name : "<<filename<<endl;
        }
};

class CSVProcessor : public IFileProcessor {
public:
    void process(const string& fileName) override {
        cout << "Processing CSV file: " << fileName << endl;
        // CSV processing logic here
    }
};

class JSONProcessor : public IFileProcessor {
public:
    void process(const string& fileName) override {
        cout << "Processing JSON file: " << fileName << endl;
        // JSON processing logic here
    }
};

class FileService {
    IFileHandler& handler;
    IFileProcessor& processor;

public:
    FileService(IFileHandler& h, IFileProcessor& p)
        : handler(h), processor(p) {}

    void handleFile(const string& fileName) {
        handler.read(fileName);
        processor.process(fileName);
        handler.write(fileName);
    }
};




int main()
{
    FileHandler fileHandler;
    CSVProcessor csvProcessor;

    FileService service(fileHandler, csvProcessor);
    service.handleFile("data.csv");
return 0;
}