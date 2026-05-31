#include<iostream>

using namespace std;


/*
==================================================
SUPPORT REQUEST
==================================================
*/

class SupportRequest {

public:

    string issueType;

    SupportRequest(
        const string& issueType
    )
        : issueType(issueType)
    {}
};



/*
==================================================
HANDLER ABSTRACT CLASS
==================================================
*/

class SupportHandler {

protected:

    SupportHandler* nextHandler;

public:

    void setNextHandler(
        SupportHandler* handler
    ) {

        nextHandler = handler;
    }

    virtual void handleRequest(
        SupportRequest* request
    ) = 0;

    virtual ~SupportHandler() {}
};



/*
==================================================
CONCRETE HANDLERS
==================================================
*/

class BasicSupport
    : public SupportHandler {

public:

    void handleRequest(
        SupportRequest* request
    ) override {

        if(request->issueType == "Password Reset") {

            cout
                << "[Basic Support] Handling Password Reset"
                << endl;
        }
        else if(nextHandler) {

            nextHandler->handleRequest(
                request
            );
        }
    }
};



class TechnicalSupport
    : public SupportHandler {

public:

    void handleRequest(
        SupportRequest* request
    ) override {

        if(request->issueType == "Server Issue") {

            cout
                << "[Technical Support] Handling Server Issue"
                << endl;
        }
        else if(nextHandler) {

            nextHandler->handleRequest(
                request
            );
        }
    }
};



class ManagerSupport
    : public SupportHandler {

public:

    void handleRequest(
        SupportRequest* request
    ) override {

        if(request->issueType == "Refund") {

            cout
                << "[Manager Support] Handling Refund Request"
                << endl;
        }
        else {

            cout
                << "No handler available for request"
                << endl;
        }
    }
};



/*
==================================================
CLIENT
==================================================
*/

int main() {

    BasicSupport basic;

    TechnicalSupport technical;

    ManagerSupport manager;


    /*
    ==============================================
    CHAIN CREATION
    ==============================================
    */

    basic.setNextHandler(
        &technical
    );

    technical.setNextHandler(
        &manager
    );


    /*
    ==============================================
    REQUESTS
    ==============================================
    */

    SupportRequest req1(
        "Password Reset"
    );

    SupportRequest req2(
        "Server Issue"
    );

    SupportRequest req3(
        "Refund"
    );

    SupportRequest req4(
        "Database Crash"
    );


    basic.handleRequest(&req1);

    basic.handleRequest(&req2);

    basic.handleRequest(&req3);

    basic.handleRequest(&req4);

    return 0;
}