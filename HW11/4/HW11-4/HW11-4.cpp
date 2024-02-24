// HW11-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Figure.h"
#include "Triangle.h"
#include "EquTriangle.h"
#include "IsoTriangle.h"
#include "RectTriangle.h"

#include "Quad.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Parallelogram.h"
#include "Square.h"

void print_info(Figure* figure) //приведение типа!
{
    figure->print_info();       //поскольку метод является виртуальным и переопределен в дочках, вызовется дочерний метод!
}


int main()
{
    setlocale(LC_ALL, "Russian");

    //треугольники
    Triangle triangle;
    print_info(&triangle);

    EquTriangle equTriangle(20);
    print_info(&equTriangle);

    IsoTriangle isoTriangle(20, 30, 45, 90);
    print_info(&isoTriangle);

    RectTriangle rectTriangle(20, 30, 40, 45, 45);
    print_info(&rectTriangle);

    //четырехугольники
    Quad quad;
    print_info(&quad);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Rhomb rhomb(20, 35, 45);
    print_info(&rhomb);

    Parallelogram parallelogram(20, 30, 35, 55);
    print_info(&parallelogram);

    Square square(20);
    print_info(&square);

    return 0;
}



