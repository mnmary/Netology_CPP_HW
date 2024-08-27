// HW4-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
};

class DataText : public Printable
{
private:
    std::string str{ "" };
public:
    DataText(std::string str):str {str} {}
    std::string print() const override
    {
       return str;
    }
};

class DataHTML : public Printable
{
private:
    std::string str{ "" };
public:
    DataHTML(std::string str) :str{ str } {}
    std::string print() const override
    {
        return "<html>" + str + "<html/>";
    }
};

class DataJSON : public Printable
{
private:
    std::string str{ "" };
public:
    DataJSON(std::string str) :str{ str } {}
    std::string print() const override
    {
        return "{ \"str\": \"" + str + "\"}";
    }
};

void saveTo(std::ofstream& file, const Printable& printable)
{
    file << printable.print();
    file << std::endl;
}

int main()
{
    Printable* printable = new DataText("This is Data text");
    Printable* printable1 = new DataHTML("This is Data HTML");
    Printable* printable2 = new DataJSON("This is Data JSON");
    
    std::ofstream file("string.txt");
    if (file.is_open())
    {
        saveTo(file, *printable);
        saveTo(file, *printable1);
        saveTo(file, *printable2);
    }
    file.close();    
    return 0;
}

