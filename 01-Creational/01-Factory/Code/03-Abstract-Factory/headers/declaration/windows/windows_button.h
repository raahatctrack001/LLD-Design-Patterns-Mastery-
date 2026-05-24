#ifndef WINDOWS_BUTTON_H
#define WINDOWS_BUTTON_H

#include<iostream>
#include"../../interface/button.h"

class WindowsButton: public Button{
    public:
        void render() override;
};

#endif