#include<iostream>

using namespace std;

class PaymentStrategy{
    public:
        virtual void pay(int amount) = 0;
        ~PaymentStrategy() {};
};


class UPIPayment: public PaymentStrategy{
    public:
        void pay(int amount) override{
            cout 
                << "Paid "
                << amount 
                << " via UPI"
                << endl;
        }
};
class CardPayment: public PaymentStrategy{
    public:
        void pay(int amount) override{
            cout 
                << "Paid "
                << amount 
                << " via Card"
                << endl;
        }
};
class IBPayment: public PaymentStrategy{
    public:
        void pay(int amount) override{
            cout 
                << "Paid "
                << amount 
                << " via IB"
                << endl;
        }
};

class PaymentService{
    PaymentStrategy *strategy;

    public: 
        PaymentService(PaymentStrategy *str): strategy(str){};

        void executePayment(int amount ){
            strategy->pay(amount);
        }
};

int main(){

    cout << "1. UPI Payment \n"
         << "2. IB Payment \n"
         << "3. Card Payment \n";
    
    int n;
    cin >> n;

    PaymentService *ps;
    switch(n){
        case 1: ps = new PaymentService (new UPIPayment()); break;
        case 2: ps = new PaymentService(new IBPayment()); break;
        case 3: ps = new PaymentService(new CardPayment()); break;
        default: ps = nullptr;
    }

    int amount;
    cout << "Enter the amount you want to pay" << endl;
    cin >> amount;

    ps->executePayment(amount);
    delete ps;

    return 0;
}
