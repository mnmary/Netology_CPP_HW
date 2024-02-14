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
    Figure(int, std::string);
    virtual void print_info();
};

