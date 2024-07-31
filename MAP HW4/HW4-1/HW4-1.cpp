// HW4-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#define M_PI 3.14159265358979323846
struct  Coord
{
    int x{ 0 };
    int y{ 0 };
    int z{ 0 };
};
class Shape
{
private:
    std::string name{ "" };
public:
    Shape(std::string name)
    {
        this->name = name;
    }
    std::string getName()
    {
        return this->name;
    }
    virtual double getSquare()
    {
        return -1;
    }

    virtual double getVolume()
    {
        return -1;
    }
    
    virtual void shift(int m, int n, int k)
    {

    }
    virtual void shift(int m, int n)
    {

    }
    virtual void scaleX(int a)
    {

    }
    virtual void scaleY(int a)
    {

    }
    virtual void scaleZ(int a)
    {

    }
    virtual void scale(int a)
    {

    }

};

class Line : public Shape
{
private:
    Coord C1;
    Coord C2;
public:
    Line(Coord C1, Coord C2) : Shape{ "line"}
    {
        this->C1 = C1;
        this->C2 = C2;
    }
    double getSquare() override
    {
        return 0;
    }
    
    double getVolume() override
    {
        return 0;
    }
    
    void shift(int m, int n) override
    {
        C1.x += m; C1.y += n;
        C2.x += m; C2.y += n;
    }

    void scaleX(int a) override
    {
        C1.x *= a;
        C2.x *= a;

    }
    void scaleY(int a) override
    {
        C1.y *= a;
        C2.y *= a;

    }
    void scaleZ(int a) override
    {
        C1.z *= a;
        C2.z *= a;

    }
    void scale(int a) override
    {
        C1.x /= a; C1.y /= a;
        C2.x /= a; C2.y /= a;

    }
    
};

class Sqr : public Shape
{
private:
    Coord C1;
    Coord C2;
    Coord C3;
    Coord C4;
public:
    Sqr(Coord C1, Coord C2, Coord C3, Coord C4) : Shape{ "sqr" }
    {
        this->C1 = C1;
        this->C2 = C2;
        this->C3 = C3;
        this->C4 = C4;
    }
    double getSquare() override
    {
        // стороны фигуры
        int a = abs(C1.x - C2.x);
        int b = abs(C1.y - C2.y);
        return a * b;
    }
    double getVolume() override
    {
        return 0;
    }
    void shift(int m, int n) override
    {
        C1.x += m; C1.y += n;
        C2.x += m; C2.y += n;
        C3.x += m; C3.y += n;
        C4.x += m; C4.y += n;

    }
    void scaleX(int a) override
    {
        C1.x *= a;
        C2.x *= a;
        C3.x *= a;
        C4.x *= a;

    }
    void scaleY(int a) override
    {
        C1.y *= a;
        C2.y *= a;
        C3.y *= a;
        C4.y *= a;

    }
    void scaleZ(int a) override
    {
        C1.z *= a;
        C2.z *= a;
        C3.z *= a;
        C4.z *= a;

    }
    void scale(int a) override
    {
        C1.x /= a; C1.y /= a;
        C2.x /= a; C2.y /= a;
        C3.x /= a; C3.y /= a;
        C4.x /= a; C4.y /= a;
    }
};



class Cube : public Shape
{
private:
    Coord C1;
    Coord C2;
    Coord C3;
    Coord C4;
    Coord C5;
    Coord C6;
    Coord C7;
    Coord C8;
public:
    Cube(Coord C1, Coord C2, Coord C3, Coord C4, Coord C5, Coord C6, Coord C7, Coord C8) : Shape{ "cube" }
    {
        this->C1 = C1;
        this->C2 = C2;
        this->C3 = C3;
        this->C4 = C4;
        this->C5 = C5;
        this->C6 = C6;
        this->C7 = C7;
        this->C8 = C8;
    }
    double getSquare() override
    {
        // стороны фигуры
        int a = abs(C1.x - C2.x);
        int b = abs(C1.y - C2.y);
        int c = abs(C1.z - C2.z);
        return 2 * a * b + 2 * a * c + 2 * b * c;
    }
    double getVolume() override
    {
        // стороны фигуры
        int a = abs(C1.x - C2.x);
        int b = abs(C1.y - C2.y);
        int c = abs(C1.z - C2.z);
        return  a * b * c;
    }
    void shift(int m, int n, int k) override
    {
        C1.x += m; C1.y += n; C1.z += k;
        C2.x += m; C2.y += n; C2.z += k;
        C3.x += m; C3.y += n; C3.z += k;
        C4.x += m; C4.y += n; C4.z += k;
        C5.x += m; C5.y += n; C5.z += k;
        C6.x += m; C6.y += n; C6.z += k;
        C7.x += m; C7.y += n; C7.z += k;
        C8.x += m; C8.y += n; C8.z += k;
 
    }
    void scaleX(int a) override
    {
        C1.x *= a;
        C2.x *= a;
        C3.x *= a;
        C4.x *= a;
        C5.x *= a;
        C6.x *= a;
        C7.x *= a;
        C8.x *= a;

    }
    void scaleY(int a) override
    {
        C1.y *= a;
        C2.y *= a;
        C3.y *= a;
        C4.y *= a;
        C5.y *= a;
        C6.y *= a;
        C7.y *= a;
        C8.y *= a;

    }
    void scaleZ(int a) override
    {
        C1.z *= a;
        C2.z *= a;
        C3.z *= a;
        C4.z *= a;
        C5.z *= a;
        C6.z *= a;
        C7.z *= a;
        C8.z *= a;

    }
    void scale(int a) override
    {
        C1.x /= a; C1.y /= a; C1.z /= a;
        C2.x /= a; C2.y /= a; C2.z /= a;
        C3.x /= a; C3.y /= a; C3.z /= a;
        C4.x /= a; C4.y /= a; C4.z /= a;
        C5.x /= a; C5.y /= a; C5.z /= a;
        C6.x /= a; C6.y /= a; C6.z /= a;
        C7.x /= a; C7.y /= a; C7.z /= a;
        C8.x /= a; C8.y /= a; C8.z /= a;

    }
};



class Circle : public Shape
{
private:
    Coord C1;
    int R;
public:
    Circle(Coord C1, int R) : Shape{ "circle" }
    {
        this->C1 = C1;
        this->R = R;
    }
    double getSquare() override
    {
        return  M_PI * R * R;
    }
    double getVolume() override
    {
        return 0;
    }
 };
 


class Cylinder : public Shape
{
private:
    Coord C1;
    int R;
    int H;
public:
    Cylinder(Coord C1, int R, int H) : Shape{ "cylinder" }
    {
        this->C1 = C1;
        this->R = R;
        this->H = H;
    }
    double getSquare() override
    {
        return M_PI * R * R + 2 * R * H;
    }
    double getVolume() override
    {
        return M_PI * R * R * H;
    }
 };
 

int main()
{
    Coord C1;
    C1.x = 10;
    C1.y = 10;
    
    Shape* pShape;
    Cylinder cylinder(C1, 10, 20);
    
    pShape = &cylinder;

    std::cout << pShape->getName() << std::endl;
    std::cout << "Square = " << pShape->getSquare() << " | Volume = " << pShape->getVolume() << std::endl;
}

