#ifndef WINDOWSUI_H
#define WINDOWSUI_H

#include<iostream>
#include"UIFactory.h"
#include"../interface/button.h"
#include"../interface/checkbox.h"
#include"../interface/scrollbar.h"

using namespace std;

class WindowsUI: public UIFactory{
    public:
        Button* createButton() override;
        Checkbox* createCheckBox() override;
        Scrollbar* createScrollbar() override;
};

#endif