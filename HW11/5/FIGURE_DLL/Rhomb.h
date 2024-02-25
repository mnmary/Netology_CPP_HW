#pragma once
#include "Quad.h"
#include <iostream>
#include "FigureAPIDefine.h"

class Rhomb :
    public Quad
{
public:
    FIGURE_API Rhomb(int , int , int );
        void FIGURE_API print_info() override;
};

