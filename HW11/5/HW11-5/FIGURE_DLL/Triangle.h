#pragma once
#include "Figure.h"
#include <iostream>

class Triangle :
    public Figure
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 30, B = 70, C = 80;
public:
    Triangle(int, int, int, int, int, int);
    Triangle();  //default
    void print_info() override;
};

