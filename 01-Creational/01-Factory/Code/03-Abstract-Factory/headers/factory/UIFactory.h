#ifndef UIFACTORY_H
#define UIFACTORY_H

#include<iostream>
#include"../interface/button.h"
#include"../interface/checkbox.h"
#include"../interface/scrollbar.h"

using namespace std;

class UIFactory{
    public:
        virtual Button* createButton() = 0;
        virtual Checkbox* createCheckBox() = 0;
        virtual Scrollbar* createScrollbar() = 0;
};

#endif