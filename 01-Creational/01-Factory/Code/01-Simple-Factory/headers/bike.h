#ifndef BIKE_H
#define BIKE_H


#include<iostream>
#include"vehicle.h"

class Bike: public Vehicle{
    public:
        void startEngine() override;
        void accelerate() override;
        void brake() override;
};

#endif