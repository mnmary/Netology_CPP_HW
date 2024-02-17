#pragma once
#include "Triangle.h"
#include <iostream>
class RectTriangle :
    public Triangle
{
public:
    RectTriangle(int , int , int , int , int );
    RectTriangle(int, int, int, int, int, int);
    void print_info() override;
};

