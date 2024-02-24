#pragma once
#include "Triangle.h"
#include <iostream>
#include "FigureAPIDefine.h"

class EquTriangle :
    public Triangle
{
public:
    FIGURE_API EquTriangle(int );
    void FIGURE_API print_info() override;
};

