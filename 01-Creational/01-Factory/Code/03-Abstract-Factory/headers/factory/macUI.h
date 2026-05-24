#ifndef MACUI_H
#define MACUI_H

#include<iostream>
#include"UIFactory.h"
#include"../interface/button.h"
#include"../interface/checkbox.h"
#include"../interface/scrollbar.h"

using namespace std;

class MacUI: public UIFactory{
    public:
        Button* createButton() override;
        Checkbox* createCheckBox() override;
        Scrollbar* createScrollbar() override;
};

#endif