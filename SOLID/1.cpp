// Single notificationservice class for sending mails based on the type to the user with a message

#include<bits/stdc++.h>
using namespace std;

struct User{
    string name;
    string email;
    string phone;
};

class NotificationService {
public:
    void sendNotification(const User &user,const string &message,const string &type){
        if(type=="email"){
            cout<<"Send email to "<<user.email<<": "<<message<<endl;
        } else if(type=="sms"){
            cout<<"Send sms to "<<user.phone<<": "<<message<<endl;
        }
    }
};

int main()
{
    User alice{"Alice","alice@gmail.com","00000001111"};
    NotificationService service;
    service.sendNotification(alice,"Hi Alice! Your order is shipped.","sms");
    return 0;
}