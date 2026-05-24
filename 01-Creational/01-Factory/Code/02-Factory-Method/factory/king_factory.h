#ifndef KING_FACTORY_H
#define KING_FACTORY_H

#include<iostream>
#include"../headers/burger.h"
#include"factory.h"

class KingBurgerFactory: public BurgerFactory{
    public:
    Burger* createBurger(std::string type) override;
};

#endif