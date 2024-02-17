#pragma once
#include "Quad.h"
#include <iostream>
class Parallelogram :
    public Quad
{
public:
    Parallelogram(int , int , int , int );
    Parallelogram(int, int, int, int, int, int, int, int);
    void print_info() override;
};

