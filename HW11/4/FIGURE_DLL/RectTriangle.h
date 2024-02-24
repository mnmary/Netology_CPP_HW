#pragma once
#include "Triangle.h"
#include <iostream>
#include "FigureAPIDefine.h"

class RectTriangle :
    public Triangle
{
public:
    FIGURE_API RectTriangle(int , int , int , int , int );
    void FIGURE_API print_info() override;
};

