#pragma once
#include "Triangle.h"
#include <iostream>
class IsoTriangle :
    public Triangle
{
public:
    IsoTriangle(int , int , int , int );
    IsoTriangle(int, int, int, int, int, int);
    void print_info() override;
};

