#include<iostream>

using namespace std;

class Light {

public:

    void turnOn() {

        cout
            << "Light turned ON"
            << endl;
    }

    void turnOff() {

        cout
            << "Light turned OFF"
            << endl;
    }
};



class Fan {

public:

    void start() {

        cout
            << "Fan started"
            << endl;
    }

    void stop() {

        cout
            << "Fan stopped"
            << endl;
    }
};



class TV {

public:

    void powerOn() {

        cout
            << "TV powered ON"
            << endl;
    }

    void powerOff() {

        cout
            << "TV powered OFF"
            << endl;
    }
};



class AC {

public:

    void switchOn() {

        cout
            << "AC switched ON"
            << endl;
    }

    void switchOff() {

        cout
            << "AC switched OFF"
            << endl;
    }
};



/*
========================================
COMMAND INTERFACE
========================================
*/

class Command {

public:

    virtual void execute() = 0;

    virtual ~Command() {}
};



/*
========================================
LIGHT COMMANDS
========================================
*/

class LightOnCommand
    : public Command {

private:

    Light* light;

public:

    LightOnCommand(
        Light* light
    )
        : light(light)
    {}

    void execute() override {

        light->turnOn();
    }
};



class LightOffCommand
    : public Command {

private:

    Light* light;

public:

    LightOffCommand(
        Light* light
    )
        : light(light)
    {}

    void execute() override {

        light->turnOff();
    }
};



/*
========================================
FAN COMMANDS
========================================
*/

class FanStartCommand
    : public Command {

private:

    Fan* fan;

public:

    FanStartCommand(
        Fan* fan
    )
        : fan(fan)
    {}

    void execute() override {

        fan->start();
    }
};



class FanStopCommand
    : public Command {

private:

    Fan* fan;

public:

    FanStopCommand(
        Fan* fan
    )
        : fan(fan)
    {}

    void execute() override {

        fan->stop();
    }
};



/*
========================================
TV COMMANDS
========================================
*/

class TVOnCommand
    : public Command {

private:

    TV* tv;

public:

    TVOnCommand(
        TV* tv
    )
        : tv(tv)
    {}

    void execute() override {

        tv->powerOn();
    }
};



class TVOffCommand
    : public Command {

private:

    TV* tv;

public:

    TVOffCommand(
        TV* tv
    )
        : tv(tv)
    {}

    void execute() override {

        tv->powerOff();
    }
};



/*
========================================
AC COMMANDS
========================================
*/

class ACOnCommand
    : public Command {

private:

    AC* ac;

public:

    ACOnCommand(
        AC* ac
    )
        : ac(ac)
    {}

    void execute() override {

        ac->switchOn();
    }
};



class ACOffCommand
    : public Command {

private:

    AC* ac;

public:

    ACOffCommand(
        AC* ac
    )
        : ac(ac)
    {}

    void execute() override {

        ac->switchOff();
    }
};



/*
========================================
INVOKER
========================================
*/

class RemoteControl {

private:

    Command* command;

public:

    void setCommand(
        Command* command
    ) {

        this->command = command;
    }

    void pressButton() {

        command->execute();
    }
};



/*
========================================
CLIENT
========================================
*/

int main() {

    Light light;
    Fan fan;
    TV tv;
    AC ac;


    LightOnCommand lightOn(&light);
    FanStartCommand fanStart(&fan);
    TVOnCommand tvOn(&tv);
    ACOnCommand acOn(&ac);

    LightOffCommand lightOff(&light);
    FanStopCommand fanStop(&fan);
    TVOffCommand tvOff(&tv);
    ACOffCommand acOff(&ac);


    RemoteControl remote;


    remote.setCommand(&lightOn);
    remote.pressButton();

    remote.setCommand(&fanStart);
    remote.pressButton();

    remote.setCommand(&tvOn);
    remote.pressButton();

    remote.setCommand(&acOn);
    remote.pressButton();

    cout << endl;


    remote.setCommand(&lightOff);
    remote.pressButton();

    remote.setCommand(&fanStop);
    remote.pressButton();

    remote.setCommand(&tvOff);
    remote.pressButton();

    remote.setCommand(&acOff);
    remote.pressButton();

    return 0;
}