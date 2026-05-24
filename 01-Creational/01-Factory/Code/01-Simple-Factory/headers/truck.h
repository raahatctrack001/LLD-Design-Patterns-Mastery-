#ifndef TRUCK_H
#define TRUCK_H


#include<iostream>
#include"vehicle.h"

class Truck: public Vehicle{
    public:
        void startEngine() override;
        void accelerate() override;
        void brake() override;
};

#endif