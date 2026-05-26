
#ifndef RAZORPAY_ADAPTER_H
#define RAZORPAY_ADAPTER_H

#include<iostream>
#include"../payment_gateway.h"
#include"../razorpay.h"

class RazorpayAdapter
    : public PaymentGateway {

private:

    RazorpayAPI* razorpay;

public:

    RazorpayAdapter(
        RazorpayAPI* r
    )
        : razorpay(r)
    {}

    void pay(
        double amount
    ) override;
};
#endif