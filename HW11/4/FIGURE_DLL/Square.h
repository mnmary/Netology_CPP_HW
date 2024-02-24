#pragma once
#include "Quad.h"
#include <iostream>
#include "FigureAPIDefine.h"

class Square :
    public Quad
{
public:
    FIGURE_API Square(int );
    void FIGURE_API print_info() override;
};

