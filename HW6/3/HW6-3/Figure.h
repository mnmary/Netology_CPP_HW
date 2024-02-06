#pragma once
#include <iostream>

class Figure
{
protected:
    int cntPoint;
    std::string name;
public:
    int getCntPoint();
    std::string getName();
    Figure();
    virtual void print_info();
};

