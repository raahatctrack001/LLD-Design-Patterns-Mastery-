#include<iostream>
#include"../headers/razorpay.h"

using namespace std;

void RazorpayAPI:: processTransaction(double amount){
        cout
            << "[Razorpay] Transaction of Rs "
            << amount
            << " completed"
            << endl;
    }