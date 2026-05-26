#include<iostream>
#include"../../headers/adapters/razorpay_adapter.h"

void RazorpayAdapter::pay(double amount){
    razorpay->processTransaction(
            amount
        );
}