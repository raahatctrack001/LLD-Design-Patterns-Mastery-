#ifndef CAR_H
#define CAR_H


#include<iostream>
#include"vehicle.h"

class Car: public Vehicle{
    public:
        void startEngine() override;
        void accelerate() override;
        void brake() override;
};

#endif