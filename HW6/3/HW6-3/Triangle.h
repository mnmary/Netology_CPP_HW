#pragma once
#include "Figure.h"

class Triangle: public Figure
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 30, B = 70, C = 80;
public:
    Triangle(int a, int b, int c, int A, int B, int C);
    Triangle();  //default
    void print_info() override;
};

