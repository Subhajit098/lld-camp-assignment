#include<bits/stdc++.h>
using namespace std;

class EmailSender{
public:
    void sendEmail(){

    }
};

class SMSSender{
public:
    void sendSMS(){

    }
};

class NotificationService{
private:
    EmailSender emailSender;
    SMSSender smsSender;
public:
    void sendNotificationService(const User &user,const string &message,
    const string &type){
        if(type=="email") emailSender.sendEmail();
        else smsSender.sendSMS();
    }
};

int main()
{

return 0;
}