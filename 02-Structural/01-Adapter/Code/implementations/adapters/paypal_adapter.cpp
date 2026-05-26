#include<iostream>
#include"../../headers/adapters/paypal_adapter.h"

void PaypalAdapter:: pay(
        double amount
    ) {

        paypal->sendPayment(
            amount
        );
    }