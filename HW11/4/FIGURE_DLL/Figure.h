#pragma once
#include <iostream>
#include "FigureAPIDefine.h"

class Figure
{
protected:
    int cntPoint;
    std::string name;
public:
    FIGURE_API int getCntPoint();
    FIGURE_API std::string getName();
    FIGURE_API Figure();
    virtual FIGURE_API void print_info();
};

