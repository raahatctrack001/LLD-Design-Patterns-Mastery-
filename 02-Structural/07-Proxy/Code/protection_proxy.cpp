#include<iostream>
#include<memory>

using namespace std;

class IUserService {

public:

    virtual void deleteUser(
        const string& username
    ) = 0;

    virtual ~IUserService() {}
};

class UserService
    : public IUserService {

public:

    void deleteUser(
        const string& username
    ) override {

        cout
            << "User deleted: "
            << username
            << endl;
    }
};

class UserServiceProxy
    : public IUserService {

private:

    unique_ptr<UserService>
        realService;

    string role;

public:

    UserServiceProxy(
        const string& role
    )
        : role(role)
    {

        realService =
            make_unique<UserService>();
    }

    void deleteUser(
        const string& username
    ) override {

        if(role != "ADMIN") {

            cout
                << "ACCESS DENIED"
                << endl;

            return;
        }

        cout
            << "[Proxy] Authentication successful"
            << endl;

        realService->deleteUser(
            username
        );
    }
};

int main() {

    IUserService* normalUser =
        new UserServiceProxy(
            "USER"
        );

    IUserService* admin =
        new UserServiceProxy(
            "ADMIN"
        );

    normalUser->deleteUser(
        "Rahul"
    );

    cout << endl;

    admin->deleteUser(
        "Aman"
    );

    delete normalUser;
    delete admin;

    return 0;
}