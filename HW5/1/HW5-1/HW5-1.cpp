// HW5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure
{
protected:
    int cntPoint;
public:
    int getCntPoint()
    {
        return cntPoint;
    }
    Figure()
    {
        cntPoint = 0;
    }
};

class Triangle : public Figure
{
public:
    Triangle()
    {
        cntPoint = 3;
    }
};

class Rectangle : public Figure
{
public:
    Rectangle()
    {
        cntPoint = 4;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Количество сторон: " << std::endl;
    Figure figure;
    std::cout << "Фигура: " << figure.getCntPoint() << std::endl;
    Triangle triangle;
    std::cout << "Треугольник: " << triangle.getCntPoint() << std::endl;
    Rectangle rectangle;
    std::cout << "Четырёхугольник: " << rectangle.getCntPoint() << std::endl;

    return 0;
}


