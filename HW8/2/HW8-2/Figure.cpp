#include "Figure.h"
#include <iostream>

    int Figure::getCntPoint()
    {
        return cntPoint;
    }
    std::string Figure::getName()
    {
        return name;
    }
    Figure::Figure()
    {
        cntPoint = 0;
        name = "";
    }
    Figure::Figure(int cntPoint, std::string name)
    {
        this->cntPoint = cntPoint;
        this->name = name;
    }
    void Figure::print_info()
    {
        std::cout << name << std::endl;
        std::cout << std::endl;
    }
