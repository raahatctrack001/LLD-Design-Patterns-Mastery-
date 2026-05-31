#include<iostream>
#include<string>
#include<memory>

using namespace std;


/*
============================================================
TEMPLATE METHOD DESIGN PATTERN
============================================================

REAL WORLD BACKEND EXAMPLE:
---------------------------

Backend API Request Processing Lifecycle

Examples:
- Login API
- Payment API
- Order API
- User Registration API

Every backend request generally follows:

1. Parse Request
2. Authenticate User
3. Validate Data
4. Execute Business Logic
5. Send Response
6. Log Request

But:
-----
Different APIs customize:

- validation
- business logic
- authentication rules
- logging behavior

This is perfect for Template Method Pattern.

============================================================
*/



/*
============================================================
REQUEST OBJECT
============================================================
*/

class HttpRequest {

public:

    string endpoint;
    string body;
    string token;

    HttpRequest(
        const string& endpoint,
        const string& body,
        const string& token
    )
        :
        endpoint(endpoint),
        body(body),
        token(token)
    {}
};



/*
============================================================
ABSTRACT TEMPLATE CLASS
============================================================
*/

class RequestHandler {

public:

    /*
    ========================================================
    TEMPLATE METHOD
    ========================================================

    Final request processing workflow.
    Order is FIXED.
    */

    void handleRequest(
        HttpRequest* request
    ) {

        parseRequest(request);

        if(!authenticate(request)) {

            cout
                << "[ERROR] Authentication Failed"
                << endl;

            return;
        }

        if(!validate(request)) {

            cout
                << "[ERROR] Validation Failed"
                << endl;

            return;
        }

        processBusinessLogic(request);

        sendResponse();

        logRequest(request);
    }



    /*
    ========================================================
    COMMON STEPS
    ========================================================
    */

    virtual void parseRequest(
        HttpRequest* request
    ) {

        cout
            << "[SYSTEM] Parsing request for endpoint: "
            << request->endpoint
            << endl;
    }



    virtual bool authenticate(
        HttpRequest* request
    ) {

        cout
            << "[SYSTEM] Authenticating token..."
            << endl;

        return request->token == "valid_token";
    }



    virtual void sendResponse() {

        cout
            << "[SYSTEM] Sending JSON response"
            << endl;
    }



    virtual void logRequest(
        HttpRequest* request
    ) {

        cout
            << "[SYSTEM] Logging request for: "
            << request->endpoint
            << endl;
    }



    /*
    ========================================================
    VARIABLE STEPS
    ========================================================
    */

    virtual bool validate(
        HttpRequest* request
    ) = 0;

    virtual void processBusinessLogic(
        HttpRequest* request
    ) = 0;



    virtual ~RequestHandler() {}
};



/*
============================================================
LOGIN API HANDLER
============================================================
*/

class LoginRequestHandler
    : public RequestHandler {

public:

    bool validate(
        HttpRequest* request
    ) override {

        cout
            << "[LOGIN API] Validating login payload..."
            << endl;

        return !request->body.empty();
    }



    void processBusinessLogic(
        HttpRequest* request
    ) override {

        cout
            << "[LOGIN API] Checking credentials..."
            << endl;

        cout
            << "[LOGIN API] Generating JWT token..."
            << endl;
    }
};



/*
============================================================
PAYMENT API HANDLER
============================================================
*/

class PaymentRequestHandler
    : public RequestHandler {

public:

    bool validate(
        HttpRequest* request
    ) override {

        cout
            << "[PAYMENT API] Validating payment data..."
            << endl;

        return request->body.find("amount")
               != string::npos;
    }



    void processBusinessLogic(
        HttpRequest* request
    ) override {

        cout
            << "[PAYMENT API] Processing payment..."
            << endl;

        cout
            << "[PAYMENT API] Deducting amount..."
            << endl;

        cout
            << "[PAYMENT API] Updating transaction DB..."
            << endl;
    }



    /*
    ========================================================
    OVERRIDDEN OPTIONAL HOOK
    ========================================================
    */

    void logRequest(
        HttpRequest* request
    ) override {

        cout
            << "[PAYMENT API] Logging secure transaction"
            << endl;
    }
};



/*
============================================================
ORDER API HANDLER
============================================================
*/

class OrderRequestHandler
    : public RequestHandler {

public:

    bool validate(
        HttpRequest* request
    ) override {

        cout
            << "[ORDER API] Validating order items..."
            << endl;

        return request->body.find("product")
               != string::npos;
    }



    void processBusinessLogic(
        HttpRequest* request
    ) override {

        cout
            << "[ORDER API] Creating order..."
            << endl;

        cout
            << "[ORDER API] Reserving inventory..."
            << endl;

        cout
            << "[ORDER API] Sending confirmation email..."
            << endl;
    }
};



/*
============================================================
CLIENT
============================================================
*/

int main() {


    /*
    ========================================================
    LOGIN REQUEST
    ========================================================
    */

    cout
        << "================ LOGIN REQUEST ================"
        << endl;

    HttpRequest loginRequest(
        "/login",
        "{username: 'rahaat', password: '123'}",
        "valid_token"
    );

    unique_ptr<RequestHandler>
        loginHandler =
            make_unique<LoginRequestHandler>();

    loginHandler->handleRequest(
        &loginRequest
    );



    cout << endl << endl;



    /*
    ========================================================
    PAYMENT REQUEST
    ========================================================
    */

    cout
        << "=============== PAYMENT REQUEST ==============="
        << endl;

    HttpRequest paymentRequest(
        "/payment",
        "{amount: 5000}",
        "valid_token"
    );

    unique_ptr<RequestHandler>
        paymentHandler =
            make_unique<PaymentRequestHandler>();

    paymentHandler->handleRequest(
        &paymentRequest
    );



    cout << endl << endl;



    /*
    ========================================================
    ORDER REQUEST
    ========================================================
    */

    cout
        << "================ ORDER REQUEST ================"
        << endl;

    HttpRequest orderRequest(
        "/order",
        "{product: 'Laptop'}",
        "valid_token"
    );

    unique_ptr<RequestHandler>
        orderHandler =
            make_unique<OrderRequestHandler>();

    orderHandler->handleRequest(
        &orderRequest
    );



    return 0;
}