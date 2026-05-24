#ifndef BASIC_H
#define BASIC_H

#include"../burger.h"

class Basic: public Burger{
    public:
        void prepare() override;
};


#endif