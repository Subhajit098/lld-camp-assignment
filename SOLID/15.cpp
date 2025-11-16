// However to illustrate,
// However, to illustrate why ISP matters, consider a scenario where we weren't so careful. Imagine we had designed a single interface INotificationService that included all possible notification-related actions, for example:

// If that was the case,
// This fat interface defines methods for every channel. If we try to implement it in a class like EmailSenderService, which is only supposed to send emails, we'd end up with something like:

// This text is setting up a scenario to demonstrate the problem caused by a monolithic interface (violating the ISP).


#include<bits/stdc++.h>
using namespace std;

struct INotificationService {
  virtual void sendEmail(const User&, const std::string&) = 0;
  virtual void sendSMS(const User&, const std::string&) = 0;
  virtual void sendPush(const User&, const std::string&) = 0;
};

class EmailSenderService : public INotificationService {
public:
  void sendEmail(const User& u, const std::string& msg) override {
    // send email
  }
  void sendSMS(const User& u, const std::string& msg) override {
    // Email service doesn't send SMS - what now?
  }
  void sendPush(const User& u, const std::string& msg) override {
    // Email service doesn't send Push notifications either
  }
};

int main()
{

return 0;
}