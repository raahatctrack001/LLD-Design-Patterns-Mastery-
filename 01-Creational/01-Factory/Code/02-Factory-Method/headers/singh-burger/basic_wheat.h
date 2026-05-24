#ifndef BASIC_WHEAT_H
#define BASIC_WHEAT_H

#include"../burger.h"

class BasicWheat: public Burger{
    public:
        void prepare() override;
};


#endif