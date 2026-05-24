
#include<iostream>
#include"../../factory/singh_factory.h"
#include"../../headers/singh-burger/basic_wheat.h"
#include"../../headers/singh-burger/premium_wheat.h"
#include"../../headers/singh-burger/standard_wheat.h"

Burger* SinghBurgerFactory::createBurger(std::string type) {
    if(type == "basic") return new BasicWheat();
    else if(type == "premium") return new PremiumWheat();
    else if(type == "standard") return new StandardWheat();
    else return nullptr;
}

