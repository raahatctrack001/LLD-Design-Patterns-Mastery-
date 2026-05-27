#include<iostream>

using namespace std;


class MessageSender{
    public:
        virtual void sendMessage(string message) = 0;
        ~MessageSender() {};
};

class EmailMessage: public MessageSender{
    public:
        void sendMessage(string message){
            cout <<
                "[Email]\n"
                << message
                << endl;
        }
};

class PushMessage: public MessageSender{
    public:
        void sendMessage(string message){
            cout <<
                "[Push Message]\n"
                << message
                << endl;
        }
};

class MobileMessage: public MessageSender{
    public:
        void sendMessage(string message){
            cout <<
                "[Mobile Message]\n"
                << message
                << endl;
        }
};

class Notification {
    protected:
        MessageSender *message;
    public:
        Notification(MessageSender *msg): message(msg){};
        virtual void notify(string msg) = 0;
        ~Notification(){};
};


class AlertNotification: public Notification{
    public:
        AlertNotification(MessageSender *msg): Notification(msg){};

        void notify(string msg) override{
            message->sendMessage(msg);
        }
};

class ReminderNotification: public Notification{
    public:
        ReminderNotification(MessageSender *msg): Notification(msg){};

        void notify(string msg) override{
            message->sendMessage(msg);
        }
};

class PromotionalNotification: public Notification{
    public:
        PromotionalNotification(MessageSender *msg): Notification(msg){};

        void notify(string msg) override{
            message->sendMessage(msg);
        }
};


int main(){
    MessageSender *emailMessage = new EmailMessage();
    MessageSender *pushMessage = new PushMessage();
    MessageSender *mobileMessage = new MobileMessage();


    Notification *alertNotification = new AlertNotification(emailMessage);
    Notification *reminderNotification = new ReminderNotification(pushMessage);
    Notification *promotionalNotification = new PromotionalNotification(mobileMessage);

    alertNotification->notify(" alert notification using email");
    reminderNotification->notify(" reminder notification using push msg");
    promotionalNotification->notify(" promotional message using mobile message");

    delete emailMessage;
    delete pushMessage;
    delete mobileMessage;
    delete alertNotification;
    delete reminderNotification;
    delete promotionalNotification;
    
    return 0;
}