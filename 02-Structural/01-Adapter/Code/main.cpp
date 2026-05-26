#include<iostream>
#include"./headers/stripe.h"
#include"./headers/razorpay.h"
#include"./headers/paypal.h"
#include"./headers/legacy_bank.h"

#include"./headers/adapters/legacy_bank_adapter.h"
#include"./headers/adapters/stripe_adapter.h"
#include"./headers/adapters/razorpay_adapter.h"
#include"./headers/adapters/paypal_adapter.h"

#include"./headers/payment_service.h"

int main() {

    //
    // THIRD-PARTY APIs
    //

    StripeAPI stripe;

    PaypalAPI paypal;

    RazorpayAPI razorpay;

    //LegacyBankAPI legacyBank;

    //
    // ADAPTERS
    //

    StripeAdapter stripeAdapter(
        &stripe
    );

    PaypalAdapter paypalAdapter(
        &paypal
    );

    RazorpayAdapter razorpayAdapter(
        &razorpay
    );

    // LegacyBankAdapter legacyAdapter(
    //     &legacyBank
    // );

    //
    // PAYMENT SERVICES
    //

    PaymentService stripeService(
        &stripeAdapter
    );

    PaymentService paypalService(
        &paypalAdapter
    );

    PaymentService razorpayService(
        &razorpayAdapter
    );

    // PaymentService legacyService(
    //     &legacyAdapter
    // );

    //
    // PAYMENTS
    //

    stripeService.checkout(
        1500
    );

    cout << endl;

    paypalService.checkout(
        2500
    );

    cout << endl;

    razorpayService.checkout(
        3500
    );

    cout << endl;

    // legacyService.checkout(
    //     4500
    // );

    return 0;
}