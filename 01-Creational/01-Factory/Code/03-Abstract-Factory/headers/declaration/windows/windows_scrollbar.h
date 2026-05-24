#ifndef WINDOWS_SCROLLBAR_H
#define WINDOWS_SCROLLBAR_H

#include<iostream>
#include"../../interface/scrollbar.h"

class WindowsScrollbar: public Scrollbar{
    public:
        void scroll() override;
};

#endif