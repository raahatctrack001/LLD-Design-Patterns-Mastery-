
#include<iostream>
#include"../../factory/king_factory.h"
#include"../../headers/king-burger/basic.h"
#include"../../headers/king-burger/premium.h"
#include"../../headers/king-burger/standard.h"

Burger* KingBurgerFactory::createBurger(std::string type) {
    if(type == "basic") return new Basic();
    else if(type == "premium") return new Premium();
    else if(type == "standard") return new Standard();
    else return nullptr;
}

