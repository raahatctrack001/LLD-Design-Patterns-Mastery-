#include<iostream>
#include"../headers/bike.h"
#include"../headers/car.h"
#include"../headers/truck.h"

using namespace std;

class Factory {
    public:
        static Vehicle* createObject(string type){
            if(type == "bike") return new Bike();
            else if(type == "car") return new Car();
            else if(type == "truck") return new Truck();
            else return nullptr;
        }
};