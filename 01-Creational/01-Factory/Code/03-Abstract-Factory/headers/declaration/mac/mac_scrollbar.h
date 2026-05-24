#ifndef MAC_SCROLLBAR_H
#define MAC_SCROLLBAR_H

#include<iostream>
#include"../../interface/scrollbar.h"

class MacScrollbar: public Scrollbar{
    public:
        void scroll() override;
};

#endif