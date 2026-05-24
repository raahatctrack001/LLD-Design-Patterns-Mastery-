#ifndef LINUXUI_H
#define LINUXUI_H

#include<iostream>
#include"UIFactory.h"
#include"../interface/button.h"
#include"../interface/checkbox.h"
#include"../interface/scrollbar.h"

using namespace std;

class LinuxUI: public UIFactory{
    public:
        Button* createButton() override;
        Checkbox* createCheckBox() override;
        Scrollbar* createScrollbar() override;
};

#endif