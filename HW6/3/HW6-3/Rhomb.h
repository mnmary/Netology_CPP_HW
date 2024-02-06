#pragma once
#include "Quad.h"
class Rhomb :
    public Quad
{
public:
    Rhomb(int a, int A, int B);
    void print_info() override;
};

