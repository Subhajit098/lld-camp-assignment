#include<bits/stdc++.h>
using namespace std;

struct INotifier{
    virtual ~INotifier()=default;
    virtual void send(const User &user,const string &message) = 0;
};

class EmailSender:public INotifier{
public:
    void send(const User &user,const string &message) override{

    }
};

class SMSSender:public INotifier{
public:
    void send(const User &user,const string &message) override{
        
    }
};

class NotificationService{
public:
    void sendViaChannel(INotifier &notifier,const User &user,const string &message){
        notifier.send(user,message);
    }
};

int main()
{
    User alice{"Alice","alice@gmail.com","00000001111"};
    NotificationService service;
    EmailSender emailSender;
    SMSSender smsSender;
    service.sendViaChannel(emailSender,alice,"hello via email");
    service.sendViaChannel(smsSender,alice,"hello via sms");
return 0;
}