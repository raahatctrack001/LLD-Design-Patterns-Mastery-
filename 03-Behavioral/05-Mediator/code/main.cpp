#include<iostream>
#include<vector>

using namespace std;


/*
================================================
MEDIATOR INTERFACE
================================================
*/

class User;

class ChatMediator {

public:

    virtual void sendMessage(
        const string& message,
        User* sender
    ) = 0;

    virtual void addUser(
        User* user
    ) = 0;

    virtual ~ChatMediator() {}
};



/*
================================================
COLLEAGUE
================================================
*/

class User {

protected:

    string name;
    ChatMediator* mediator;

public:

    User(
        string name,
        ChatMediator* mediator
    )
        : name(name),
          mediator(mediator)
    {}

    virtual void send(
        const string& message
    ) = 0;

    virtual void receive(
        const string& message
    ) = 0;

    virtual ~User() {}
};



/*
================================================
CONCRETE MEDIATOR
================================================
*/

class ChatRoom
    : public ChatMediator {

private:

    vector<User*> users;

public:

    void addUser(
        User* user
    ) override {

        users.push_back(user);
    }

    void sendMessage(
        const string& message,
        User* sender
    ) override {

        for(auto user : users) {

            if(user != sender) {

                user->receive(message);
            }
        }
    }
};



/*
================================================
CONCRETE COLLEAGUE
================================================
*/

class ChatUser
    : public User {

public:

    ChatUser(
        string name,
        ChatMediator* mediator
    )
        : User(name, mediator)
    {}

    void send(
        const string& message
    ) override {

        cout
            << name
            << " sends: "
            << message
            << endl;

        mediator->sendMessage(
            message,
            this
        );
    }

    void receive(
        const string& message
    ) override {

        cout
            << name
            << " received: "
            << message
            << endl;
    }
};



/*
================================================
CLIENT
================================================
*/

int main() {

    ChatRoom chatRoom;


    ChatUser user1(
        "Rahaat",
        &chatRoom
    );

    ChatUser user2(
        "Aman",
        &chatRoom
    );

    ChatUser user3(
        "Ali",
        &chatRoom
    );


    chatRoom.addUser(&user1);
    chatRoom.addUser(&user2);
    chatRoom.addUser(&user3);


    user1.send(
        "Hello Everyone!"
    );

    cout << endl;

    user2.send(
        "Hi Rahaat!"
    );

    return 0;
}