#pragma once
#include "Quad.h"
class Parallelogram :
    public Quad
{
public:
    Parallelogram(int a, int b, int A, int B);
    void print_info() override;
};

