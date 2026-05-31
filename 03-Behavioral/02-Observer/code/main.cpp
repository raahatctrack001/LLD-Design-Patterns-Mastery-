#include<iostream>
#include<vector>
#include<memory>

using namespace std;


/*
========================================
OBSERVER INTERFACE
========================================
*/

class Observer {

public:

    virtual void update(
        const string& message
    ) = 0;

    virtual ~Observer() {}
};



/*
========================================
CONCRETE OBSERVERS
========================================
*/

class EmailNotification
    : public Observer {

public:

    void update(
        const string& message
    ) override {

        cout
            << "[EMAIL] "
            << message
            << endl;
    }
};



class SMSNotification
    : public Observer {

public:

    void update(
        const string& message
    ) override {

        cout
            << "[SMS] "
            << message
            << endl;
    }
};



class PushNotification
    : public Observer {

public:

    void update(
        const string& message
    ) override {

        cout
            << "[PUSH] "
            << message
            << endl;
    }
};



/*
========================================
SUBJECT
========================================
*/

class NotificationService {

private:

    vector<Observer*> observers;

public:

    void subscribe(
        Observer* observer
    ) {

        observers.push_back(observer);
    }


    void notifyUsers(
        const string& message
    ) {

        for(auto observer : observers) {

            observer->update(message);
        }
    }
};



/*
========================================
CLIENT
========================================
*/

int main() {

    NotificationService service;

    EmailNotification email;
    SMSNotification sms;
    PushNotification push;

    service.subscribe(&email);
    service.subscribe(&sms);
    service.subscribe(&push);

    service.notifyUsers(
        "Big Billion Day Sale Started!"
    );

    return 0;
}