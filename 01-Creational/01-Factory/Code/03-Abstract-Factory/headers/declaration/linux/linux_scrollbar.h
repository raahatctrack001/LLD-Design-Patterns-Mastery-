#ifndef LINUX_SCROLLBAR_H
#define LINUX_SCROLLBAR_H

#include<iostream>
#include"../../interface/scrollbar.h"

class LinuxScrollbar: public Scrollbar{
    public:
        void scroll() override;
};

#endif