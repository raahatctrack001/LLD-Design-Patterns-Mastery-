#include<iostream>
#include"../../headers/adapters/legacy_bank_adapter.h"

using namespace std;
void LegacyBankAdapter:: pay(
        double amount
    ) {

        cout
            << "[Adapter] Converting request..."
            << endl;

        bank->makeTransaction(
            amount
        );
    }