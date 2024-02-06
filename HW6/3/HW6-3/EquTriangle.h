#pragma once
#include "Triangle.h"
class EquTriangle :
    public Triangle
{
public:
    EquTriangle(int a);
    void print_info() override;
};

