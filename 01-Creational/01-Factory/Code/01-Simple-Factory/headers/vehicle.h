#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
class Vehicle{
    public:
        virtual void startEngine() = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
};

#endif