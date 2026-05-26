#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

#include<iostream>
#include"../headers/payment_gateway.h"
using namespace std;

class PaymentService {

private:

    PaymentGateway* gateway;

public:

    PaymentService(
        PaymentGateway* g
    )
        : gateway(g)
    {}

    void checkout(
        double amount
    );
};

#endif