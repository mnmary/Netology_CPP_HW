#pragma once
#include "Quad.h"
class Square :
    public Quad
{
public:
    Square(int a);
    void print_info() override;
};

