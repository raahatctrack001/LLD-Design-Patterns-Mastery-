
#ifndef LEGACY_BANK_ADAPTER_H
#define LEGACY_BANK_ADAPTER_H

#include<iostream>
#include"../payment_gateway.h"
#include"../legacy_bank.h"

class LegacyBankAdapter
    : public PaymentGateway {

private:

    LegacyBankAPI* bank;

public:

    LegacyBankAdapter(
        LegacyBankAPI* b
    )
        : bank(b)
    {}

    void pay(
        double amount
    ) override;
};

#endif