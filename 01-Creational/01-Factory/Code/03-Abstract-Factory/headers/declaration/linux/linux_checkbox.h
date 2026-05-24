#ifndef LINUX_CHECKBOX_H
#define LINUX_CHECKBOX_H

#include<iostream>
#include"../../interface/checkbox.h"

class LinuxCheckbox: public Checkbox{
    public:
        void check() override;
};

#endif