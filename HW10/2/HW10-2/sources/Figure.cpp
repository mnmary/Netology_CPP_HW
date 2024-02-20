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
    void Figure::print_info()
    {
        std::cout << name << std::endl;
        std::cout << std::endl;
    }
