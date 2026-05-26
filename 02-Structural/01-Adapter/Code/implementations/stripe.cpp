#include<iostream>

#include"../headers/stripe.h"
using namespace std;

void StripeAPI::makeStripePayment(double amount) {
        cout
            << "[Stripe] Payment of Rs "
            << amount
            << " successful"
            << endl;
    }
