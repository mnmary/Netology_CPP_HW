#pragma once
#include "Figure.h"
#include <iostream>
#include "FigureAPIDefine.h"


class Triangle :
    public Figure
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 30, B = 70, C = 80;
public:
    FIGURE_API Triangle(int, int, int, int, int, int);
    FIGURE_API Triangle();  //default
    void FIGURE_API print_info() override;
};

