#include<iostream>
#include"../headers/payment_service.h"
using namespace std;

void PaymentService :: checkout(
        double amount
    ) {

        cout
            << "Initiating payment..."
            << endl;

        gateway->pay(amount);

        cout
            << "Payment completed"
            << endl;
    }