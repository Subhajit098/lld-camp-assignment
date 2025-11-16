#include<bits/stdc++.h>
using namespace std;

class Parent{
    public: 
        void show(){
            cout<<"Parent.show"<<endl;
        }
    private: 
        void hidden(){
            cout<<"Parent.hidden"<<endl;
        }
};

class Child: public Parent{
    public:
        void hidden(){
            cout<<"Children.hidden"<<endl;
        }
};

int main()
{
    Child c;
    Parent p=c;
    p.show();
    // p.hidden();  => error 
    return 0;
}