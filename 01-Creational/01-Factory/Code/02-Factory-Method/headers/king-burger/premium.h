#ifndef PREMIUM_H
#define PREMIUM_H

#include"../burger.h"

class Premium: public Burger{
    public:
        void prepare() override;
};


#endif