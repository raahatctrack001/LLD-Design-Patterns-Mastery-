#ifndef MAC_BUTTON_H
#define MAC_BUTTON_H

#include<iostream>
#include"../../interface/button.h"

class MacButton: public Button{
    public:
        void render() override;
};

#endif