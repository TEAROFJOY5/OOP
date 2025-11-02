#include <iostream>
#include <string>
using namespace std;

class Notification {
protected:
    string recipient; 
public:
    Notification(const string& recipient) {
        this->recipient = recipient;
    }

    virtual bool validate() const {
        return !recipient.empty();
    }

    virtual string channelName() const = 0;

    virtual void send(const string& message) const = 0;

    virtual ~Notification() {}
};
class EmailNotification : public Notification {
    string emailAddress;
    string subject;

public:
    EmailNotification(const string& recipient, const string& email, const string& subject)
        : Notification(recipient), emailAddress(email), subject(subject) {}

   bool validate() const override {
    return (emailAddress.find('@') != string::npos) ? true : false;
}

    string channelName() const override {
        return "Email";
    }

    void send(const string& message) const override {
        cout << "[Email Notification]" << endl;
        cout << "Recipient: " << recipient << endl;
        cout << "Email: " << emailAddress << endl;
        cout << "Subject: " << subject << endl;
        cout << "Message: " << message << endl;
        cout << "Status: Email sent successfully!" << endl;
    }
};

class SMSNotification : public Notification {
    string phoneNumber;

public:
    SMSNotification(const string& recipient, const string& phone)
        : Notification(recipient), phoneNumber(phone) {}

    bool validate() const override {
        return (phoneNumber.size() >= 10 && phoneNumber.find_first_not_of("0333456789") == string::npos);
    }

    string channelName() const override {
        return "SMS";
    }

    void send(const string& message) const override {
        cout << "[SMS Notification]" << endl;
        cout << "Recipient: " << recipient << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Message: " << message << endl;
        cout << "Status: SMS was sent successfully!" << endl;
    }
};
class PushNotification : public Notification {
    string deviceToken;

public:
    PushNotification(const string& recipient, const string& token)
        : Notification(recipient), deviceToken(token) {}

    bool validate() const override {

        return !deviceToken.empty();
    }

    string channelName() const override {
        return "Push Notification";
    }

    void send(const string& message) const override {
        cout << "[Push Notification]" << endl;
        cout << "Recipient: " << recipient << endl;
        cout << "Device Token: " << deviceToken << endl;
        cout << "Message: " << message << endl;
        cout << "Status: Push notification delivered!" << endl;
    }
};

int main() {
    cout << "Turab Ali 24k-0651" << endl << endl;

    EmailNotification e1( "Turab Ali", "k240651@nu.edu.pk", "Order Updates");
    SMSNotification s1("Taqi", "03321234567");
    PushNotification p1("Sher Ali ", "device_token_new123");

    Notification* notifications[] = { &e1, &s1, &p1 };

    string message = "Your order has been shipped successfully!";

    for (Notification* n : notifications) {
        cout << "Channel: " << n->channelName() << endl;

        if (n->validate()) {
            n->send(message);
        } else {
            cout << "Invalid recipient details! Cannot send message." << endl;
        }
    }

    return 0;
}
