#include<iostream>
#include"../../headers/adapters/stripe_adapter.h"

void StripeAdapter:: pay(
        double amount
    ) {

        stripe->makeStripePayment(
            amount
        );
    }