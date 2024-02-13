#pragma once
#include <stdexcept>
#include <iostream>

// Пользовательский класс исключений  
// объявлен производным от стандартного класса исключений.
class MyException : public std::exception {
protected:
    std::string err;
public:
    MyException(const std::string);
    virtual const char* what() const override;
};

//в программе:
//throw MyException(<ошибка>);
//catch (const MyException& ex) { std::cout << ex.what() << std::endl; }

