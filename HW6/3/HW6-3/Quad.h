#pragma once
#include "Figure.h"
#include <iostream>
class Quad :
    public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 30, B = 40, C = 50, D = 60;
public:
    Quad(int , int , int , int , int , int , int , int );
    Quad();  //default
    void print_info() override;
};

