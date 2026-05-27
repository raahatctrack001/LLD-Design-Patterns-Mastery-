#include<iostream>

using namespace std;

class MessageSender{
    public:
        virtual void sendMessage(string& message) = 0;
        ~MessageSender(){}
};

class EmailMessage: public MessageSender{
    public:
        void sendMessage(string &message) override{
            cout <<
                "Email" + message
                <<endl;
        }
};

class PushMessage: public MessageSender{
    public:
        void sendMessage(string& message) override{
            cout <<
                "Push Message" + message
                <<endl;
        }
};

class MobileMessage: public MessageSender{
    public:
        void sendMessage(string &message) override{
            cout << 
                "Mobile Message" + message
                <<endl;
        }
};

class Notification {
    protected:
        MessageSender *message;
    public:
        Notification(MessageSender *msg): message(msg) {}; 

        virtual void notify(string msg) = 0;
        ~Notification() {};
};

class AlertNotification: public Notification{
    public:
        AlertNotification(MessageSender *s): Notification(s) {};
        
        void notify(string msg) override {
            message->sendMessage(msg);
        }
};

class ReminderNotification: public Notification{
    public:
        ReminderNotification(MessageSender *s): Notification(s){};

        void notify(string msg)override {
            message->sendMessage(msg);
        }
};

class PromotionalNotification: public Notification{
    public: 
        PromotionalNotification(MessageSender *s): Notification(s){};

        void notify(string msg)override {
            message->sendMessage(msg);
        }
};

int main(){
    MessageSender *email = new EmailMessage();
    MessageSender *pm = new MobileMessage();
    MessageSender *push = new PushMessage();

    Notification *alert = new AlertNotification(email);
    Notification *rem = new ReminderNotification(pm);
    Notification *pn = new PromotionalNotification(email);

    alert->notify(" alert");
    rem->notify(" reminder");
    pn->notify(" promotional");

    return 0;
}