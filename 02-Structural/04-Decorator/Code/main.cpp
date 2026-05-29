#include<iostream>

using namespace std;

class Coffee {
public:
    virtual string getDescription() = 0;
    virtual int getCost() = 0;
    virtual ~Coffee() {}
};

class Espresso : public Coffee {

public:

    string getDescription() override {
        return "Espresso";
    }

    int getCost() override {
        return 100;
    }
};

class CoffeeDecorator : public Coffee {

protected:
    Coffee* coffee;

public:

    CoffeeDecorator(Coffee* c)
        : coffee(c) {}
};

class MilkDecorator : public CoffeeDecorator {

public:

    MilkDecorator(Coffee* c)
        : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + ", Milk";
    }

    int getCost() override {
        return coffee->getCost() + 20;
    }
};

class ChocolateDecorator : public CoffeeDecorator {

public:

    ChocolateDecorator(Coffee* c)
        : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + ", Chocolate";
    }

    int getCost() override {
        return coffee->getCost() + 30;
    }
};

int main(){

    Coffee* coffee = new Espresso();

    coffee = new MilkDecorator(coffee);

    coffee = new ChocolateDecorator(coffee);

    cout << coffee->getDescription() << endl;

    cout << coffee->getCost() << endl;
    
    return 0;
}