// HW8-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include "Figure.h"
#include "Triangle.h"
#include "Quad.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"
#include "RectTriangle.h"
#include "IsoTriangle.h"
#include "EquTriangle.h"

#include "MyException.h"

void print_info(Figure* figure) //приведение типа!
{
    figure->print_info();       //поскольку метод является виртуальным и переопределен в дочках, вызовется дочерний метод!
}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try 
    {
        Triangle triangle;//треугольник
        print_info(&triangle);
        EquTriangle equTriangle(10);    //равносторонний треугольник
        print_info(&equTriangle);
        IsoTriangle isoTriangle(20, 20, 45, 90);    //равнобедренный треугольник
        print_info(&isoTriangle);
        RectTriangle rectTriangle(20, 30, 40, 45, 45);  //прямоугольный треугольник
        print_info(&rectTriangle);

        Quad quad;          //четырехугольник
        print_info(&quad);
        _Rectangle rectangle(50, 20);   //прямоугольник
        print_info(&rectangle);
        Parallelogram parallelogram(20, 30, 45, 135);   //параллелограм
        print_info(&parallelogram);
        Rhomb rhomb(20, 90, 90);    //ромб
        print_info(&rhomb);
        Square square(20);  //квадрат
        print_info(&square);
    }

    catch (const MyException& e) 
    {
        std::cout << e.what();
        std::cout << std::endl;
    }
    
    return 0;
}


