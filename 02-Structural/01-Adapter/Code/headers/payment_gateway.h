#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H

class PaymentGateway {

public:

    virtual void pay(
        double amount
    ) = 0;

    virtual ~PaymentGateway() {}
};

#endif