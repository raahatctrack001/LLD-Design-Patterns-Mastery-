#ifndef PREMIUM_WHEAT_H
#define PREMIUM_WHEAT_H

#include"../burger.h"

class PremiumWheat: public Burger{
    public:
        void prepare() override;
};


#endif