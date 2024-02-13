#pragma once
#include "Figure.h"
#include <iostream>
class Quad :
    public Figure
{
protected:
    int a = 10, b = 20, c = 10, d = 20;
    int A = 60, B = 120, C = 60, D = 120;
public:
    Quad(int , int , int , int , int , int , int , int );
    Quad();  //default
    void print_info() override;
};

