#pragma once
#include "Triangle.h"
#include <iostream>
class EquTriangle :
    public Triangle
{
public:
    EquTriangle(int );
    void print_info() override;
};

