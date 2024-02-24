#pragma once
#include "Quad.h"
#include <iostream>
class Square :
    public Quad
{
public:
    Square(int );
    void print_info() override;
};

