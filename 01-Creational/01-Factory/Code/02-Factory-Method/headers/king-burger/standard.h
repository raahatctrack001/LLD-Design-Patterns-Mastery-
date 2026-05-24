#ifndef STANDARD_H
#define STANDARD_H

#include"../burger.h"

class Standard: public Burger{
    public:
        void prepare() override;
};


#endif