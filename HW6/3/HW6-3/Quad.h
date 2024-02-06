#pragma once
#include "Figure.h"
class Quad :
    public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 30, B = 40, C = 50, D = 60;
public:
    Quad(int a, int b, int c, int d, int A, int B, int C, int D);
    Quad();  //default
    void print_info() override;
};

