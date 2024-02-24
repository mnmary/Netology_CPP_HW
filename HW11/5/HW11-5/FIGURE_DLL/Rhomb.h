#pragma once
#include "Quad.h"
#include <iostream>
class Rhomb :
    public Quad
{
public:
    Rhomb(int , int , int );
        void print_info() override;
};

