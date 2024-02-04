// HW5-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

//фигура
class Figure
{
protected:
    int cntPoint;
    std::string name;
public:
    int getCntPoint()
    {
        return cntPoint;
    }
    std::string getName()
    {
        return name;
    }
    Figure()
    {
        cntPoint = 0;
        name = "Фигура";
    }
    virtual bool checkFigure()
    {
        if ((cntPoint == 0) && (name == "Фигура"))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual void print_info()
    {
        std::cout << name << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << std::endl;
    }
};

//произвольный треугольник - исходный
class Triangle : public Figure
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 30, B = 70, C = 90;
public:
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

        this->name = "Треугольник";
    }
    Triangle()  //default
    {
        cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

        this->name = "Треугольник";
    }
    bool checkFigure() override
    {
        if ((cntPoint == 3)&&((A+B+C) == 180))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
};

//произвольный четырехугольник - исходный
class Quad : public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 30, B = 40, C = 50, D = 60;
public:
    Quad(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        cntPoint = 4;

        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

        this->name = "Четырехугольник";
    }
    Quad()  //default
    {
        cntPoint = 4;

        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

        this->name = "Четырехугольник";
    }
    bool checkFigure() override
    {
        if ((cntPoint == 4) && ((A + B + C + D) == 360))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
};
//прямоугольник - производный
class Rectangle : public Quad
{
public:
    Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "Прямоугольник";
    }
    bool checkFigure() override
    {
        if (((a == c) && (b == d)) && ((A==90) && (B==90) && (C==90) && (D==90)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
};

//квадрат - производный
class Square : public Quad
{
public:
    Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = "Квадрат";
    }
    bool checkFigure() override
    {
        if (((a == c) && (b == d) && (a == b)) && ((A == 90) && (B == 90) && (C == 90) && (D == 90)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
};
//параллелограмм - производный
class Parallelogram : public Quad
{
public:
    Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
    {
        this->name = "Параллелограмм";
    }
    bool checkFigure() override
    {
        if (((a == c) && (b == d)) && ((A == C) && (B == D)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
};
//ромб - производный
class Rhomb : public Quad
{
public:
    Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
    {
        this->name = "Ромб";
    }
    bool checkFigure() override
    {
        if (((a == c) && (b == d) && (a == b)) && ((A == C) && (B == D)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
};
//прямоугольный треугольник
class RectTriangle : public Triangle
{
public:
    RectTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        this->name = "Прямоугольный треугольник";
    }
    bool checkFigure() override
    {
        if (C == 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
};
//равнобедренный треугольник
class IsoTriangle : public Triangle
{
public:
    IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "Равнобедренный треугольник";
    }
    bool checkFigure() override
    {
        if ((a == c) && (A == C))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
};
//равносторонний треугольник
class EquTriangle : public Triangle
{
public:
    EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "Равносторонний треугольник";
    }
    bool checkFigure() override
    {
        if (((a == c) && (b == c) && (a == b)) && ((A == 60) && (B == 60) && (C == 60)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_info() override
    {
        std::cout << name << ": " << std::endl;
        if (checkFigure())
        {
            std::cout << "правильная" << std::endl;
        }
        else
        {
            std::cout << "неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << cntPoint << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
};

void print_info(Figure* figure) //приведение типа!
{
    figure->print_info();       //поскольку метод является виртуальным и переопределен в дочках, вызовется дочерний метод!
}
int main()
{
    setlocale(LC_ALL, "Russian");

    //фигура
    Figure figure;
    print_info(&figure);
     
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




