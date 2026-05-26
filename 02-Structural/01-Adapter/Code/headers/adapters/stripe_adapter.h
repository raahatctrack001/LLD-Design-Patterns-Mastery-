
#ifndef STRIPE_ADAPTER_H
#define STRIPE_ADAPTER_H

#include<iostream>
#include"../payment_gateway.h"
#include"../stripe.h"

class StripeAdapter
    : public PaymentGateway {

private:

    StripeAPI* stripe;

public:

    StripeAdapter(
        StripeAPI* s
    )
        : stripe(s)
    {}

    void pay(double amount) override;
};

#endif