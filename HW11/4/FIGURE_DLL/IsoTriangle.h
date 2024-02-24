#pragma once
#include "Triangle.h"
#include <iostream>
#include "FigureAPIDefine.h"

class IsoTriangle :
    public Triangle
{
public:
    FIGURE_API IsoTriangle(int , int , int , int );
    void FIGURE_API print_info() override;
};

