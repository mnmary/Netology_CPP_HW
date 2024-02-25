#pragma once
#include "Quad.h"
#include <iostream>
class Rectangle :
    public Quad
{
public:
    Rectangle(int , int );
    void print_info() override;
};

