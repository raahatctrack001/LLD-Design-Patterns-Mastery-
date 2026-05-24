#ifndef WINDOWS_CHECKBOX_H
#define WINDOWS_CHECKBOX_H

#include<iostream>
#include"../../interface/checkbox.h"

class WindowsCheckbox: public Checkbox{
    public:
        void check() override;
};

#endif