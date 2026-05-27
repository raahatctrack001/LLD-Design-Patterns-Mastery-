#include<iostream>

using namespace std;

class MessageSender {

public:

    virtual void sendMessage(
        const string& message
    ) = 0;

    virtual ~MessageSender() {}
};

class EmailSender
    : public MessageSender {

public:

    void sendMessage(
        const string& message
    ) override {

        cout
            << "[EMAIL] "
            << message
            << endl;
    }
};

class SMSSender
    : public MessageSender {

public:

    void sendMessage(
        const string& message
    ) override {

        cout
            << "[SMS] "
            << message
            << endl;
    }
};

class PushSender
    : public MessageSender {

public:

    void sendMessage(
        const string& message
    ) override {

        cout
            << "[PUSH] "
            << message
            << endl;
    }
};

class Notification {

protected:

    MessageSender* sender;

public:

    Notification(
        MessageSender* s
    )
        : sender(s)
    {}

    virtual void notify(
        const string& message
    ) = 0;

    virtual ~Notification() {}
};

class AlertNotification
    : public Notification {

public:

    AlertNotification(
        MessageSender* s
    )
        : Notification(s)
    {}

    void notify(
        const string& message
    ) override {

        sender->sendMessage(
            "[ALERT] " + message
        );
    }
};

class ReminderNotification
    : public Notification {

public:

    ReminderNotification(
        MessageSender* s
    )
        : Notification(s)
    {}

    void notify(
        const string& message
    ) override {

        sender->sendMessage(
            "[REMINDER] " + message
        );
    }
};

class PromotionNotification
    : public Notification {

public:

    PromotionNotification(
        MessageSender* s
    )
        : Notification(s)
    {}

    void notify(
        const string& message
    ) override {

        sender->sendMessage(
            "[PROMOTION] " + message
        );
    }
};

int main() {

    MessageSender* email =
        new EmailSender();

    MessageSender* sms =
        new SMSSender();

    MessageSender* push =
        new PushSender();

    Notification* n1 =
        new AlertNotification(email);

    Notification* n2 =
        new ReminderNotification(sms);

    Notification* n3 =
        new PromotionNotification(push);

    n1->notify(
        "Server Down!"
    );

    n2->notify(
        "Meeting at 6 PM"
    );

    n3->notify(
        "50% OFF Sale!"
    );

    delete n1;
    delete n2;
    delete n3;

    delete email;
    delete sms;
    delete push;

    return 0;
}