#pragma once
#include "Quad.h"
class Rectangle :
    public Quad
{
public:
    Rectangle(int a, int b);
    void print_info() override;
};

