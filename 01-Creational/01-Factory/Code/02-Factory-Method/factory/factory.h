#ifndef FACTORY_H
#define FACTORY_H

#include<iostream>
#include"../headers/burger.h"

class BurgerFactory{
    public:
    virtual Burger* createBurger(std::string type) = 0;
};

#endif