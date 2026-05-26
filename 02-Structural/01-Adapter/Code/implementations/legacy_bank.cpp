#include<iostream>
#include"../headers/legacy_bank.h"

using namespace std;

void LegacyBankAPI::makeTransaction(
        double value
    ) {

        cout
            << "[Legacy Bank] Transaction of Rs "
            << value
            << " completed"
            << endl;
    }