#ifndef MAC_CHECKBOX_H
#define MAC_CHECKBOX_H

#include<iostream>
#include"../../interface/checkbox.h"

class MacCheckbox: public Checkbox{
    public:
        void check() override;
};

#endif