#ifndef STANDARD_WHEAT_H
#define STANDARD_WHEAT_H

#include"../burger.h"

class StandardWheat: public Burger{
    public:
        void prepare() override;
};


#endif