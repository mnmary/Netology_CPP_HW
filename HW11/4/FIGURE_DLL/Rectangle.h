#pragma once
#include "Quad.h"
#include <iostream>
#include "FigureAPIDefine.h"

class Rectangle :
    public Quad
{
public:
    FIGURE_API Rectangle(int , int );
    void FIGURE_API print_info() override;
};

