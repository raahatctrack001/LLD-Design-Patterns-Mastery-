#ifndef Singh_FACTORY_H
#define Singh_FACTORY_H

#include<iostream>
#include"../headers/burger.h"
#include"factory.h"

class SinghBurgerFactory: public BurgerFactory{
    public:
    Burger* createBurger(std::string type) override;
};

#endif