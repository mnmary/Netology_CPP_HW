#pragma once
#include "Triangle.h"
#include <iostream>
class EquTriangle :
    public Triangle
{
public:
    EquTriangle(int );
    EquTriangle(int, int, int, int, int, int);
    void print_info() override;
};

