
#ifndef PAYPAL_ADAPTER_H
#define PAYPAL_ADAPTER_H

#include<iostream>
#include"../payment_gateway.h"
#include"../paypal.h"

class PaypalAdapter
    : public PaymentGateway {

private:

    PaypalAPI* paypal;

public:

    PaypalAdapter(
        PaypalAPI* p
    )
        : paypal(p)
    {}

    void pay(
        double amount
    ) override;
};

#endif