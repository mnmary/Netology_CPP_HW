#pragma once
#include "Quad.h"
#include <iostream>
class _Rectangle :
    public Quad
{
public:
    _Rectangle(int , int );
    _Rectangle(int, int, int, int, int, int, int, int);
    void print_info() override;
};

