#pragma once
#include "Quad.h"
#include <iostream>
class Square :
    public Quad
{
public:
    Square(int );
    Square(int, int, int, int, int, int, int, int);
    void print_info() override;
};

