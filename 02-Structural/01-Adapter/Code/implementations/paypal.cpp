#include<iostream>
#include"../headers/paypal.h"
using namespace std;

void PaypalAPI:: sendPayment(
        double value
    ) {

        cout
            << "[PayPal] Payment of Rs "
            << value
            << " successful"
            << endl;
    }