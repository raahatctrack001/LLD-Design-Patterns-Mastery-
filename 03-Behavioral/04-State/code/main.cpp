#include<iostream>
#include<memory>

using namespace std;


/*
==================================================
STATE INTERFACE
==================================================

Real World Web Dev Use Case:
----------------------------

Order Processing System

Possible States:
- Created
- Paid
- Shipped
- Delivered

Behavior changes based on current state.
==================================================
*/

class OrderState {

public:

    virtual void next(class OrderContext* order) = 0;
    virtual void showStatus() = 0;
    virtual ~OrderState() {}
};



/*
==================================================
CONTEXT
==================================================
*/

class OrderContext {

private:

    OrderState* currentState;

public:

    OrderContext(
        OrderState* state
    )
        : currentState(state)
    {}

    void setState(
        OrderState* state
    ) {

        currentState = state;
    }

    void nextState() {

        currentState->next(this);
    }

    void showCurrentStatus() {

        currentState->showStatus();
    }
};



/*
==================================================
CONCRETE STATES
==================================================
*/

class PaidState;
class ShippedState;
class DeliveredState;



class CreatedState
    : public OrderState {

public:

    void next(
        OrderContext* order
    ) override;

    void showStatus() override {

        cout
            << "Order Created"
            << endl;
    }
};



class PaidState
    : public OrderState {

public:

    void next(
        OrderContext* order
    ) override;

    void showStatus() override {

        cout
            << "Payment Completed"
            << endl;
    }
};



class ShippedState
    : public OrderState {

public:

    void next(
        OrderContext* order
    ) override;

    void showStatus() override {

        cout
            << "Order Shipped"
            << endl;
    }
};



class DeliveredState
    : public OrderState {

public:

    void next(
        OrderContext* order
    ) override {

        cout
            << "Order Already Delivered"
            << endl;
    }

    void showStatus() override {

        cout
            << "Order Delivered"
            << endl;
    }
};



/*
==================================================
STATE TRANSITIONS
==================================================
*/

void CreatedState::next(
    OrderContext* order
) {

    order->setState(
        new PaidState()
    );
}



void PaidState::next(
    OrderContext* order
) {

    order->setState(
        new ShippedState()
    );
}



void ShippedState::next(
    OrderContext* order
) {

    order->setState(
        new DeliveredState()
    );
}



/*
==================================================
CLIENT
==================================================
*/

int main() {

    OrderContext order(
        new CreatedState()
    );


    order.showCurrentStatus();
    order.nextState();


    order.showCurrentStatus();
    order.nextState();


    order.showCurrentStatus();
    order.nextState();


    order.showCurrentStatus();
    order.nextState();

    return 0;
}