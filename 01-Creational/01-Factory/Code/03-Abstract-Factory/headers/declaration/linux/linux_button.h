#ifndef LINUX_BUTTON_H
#define LINUX_BUTTON_H

#include<iostream>
#include"../../interface/button.h"

class LinuxButton: public Button{
    public:
        void render() override;
};

#endif