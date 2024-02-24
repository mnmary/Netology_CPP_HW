#pragma once
#include "Quad.h"
#include <iostream>
#include "FigureAPIDefine.h"

class Parallelogram :
    public Quad
{
public:
    FIGURE_API Parallelogram(int , int , int , int );
    void FIGURE_API print_info() override;
};

