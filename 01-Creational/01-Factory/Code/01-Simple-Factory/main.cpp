#include<iostream>
#include"./headers/vehicle.h"
#include"./headers/car.h"
#include"./implementations/factory.cpp"

int main(){

    string type;
    cout<<"Enter the type of object you want: \n";
    cin>>type;
    Vehicle *v = Factory::createObject(type);

    if(!v){
        cout<<"wrong choice\n";
    }
    else{
        v->startEngine();
        v->accelerate();
        v->brake();
    }

    delete v;

    return 0;
}