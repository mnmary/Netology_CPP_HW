#pragma once
#include "Triangle.h"
class IsoTriangle :
    public Triangle
{
public:
    IsoTriangle(int a, int b, int A, int B);
    void print_info() override;
 };

