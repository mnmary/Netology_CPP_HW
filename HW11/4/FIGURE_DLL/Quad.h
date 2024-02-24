#pragma once
#include "Figure.h"
#include <iostream>
#include "FigureAPIDefine.h"

class Quad :
    public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 30, B = 40, C = 50, D = 60;
public:
    FIGURE_API Quad(int , int , int , int , int , int , int , int );
    FIGURE_API  Quad();  //default
    void FIGURE_API print_info() override;
};

