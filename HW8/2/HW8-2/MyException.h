#pragma once
#include <stdexcept>
#include <iostream>

// ���������������� ����� ����������  
// �������� ����������� �� ������������ ������ ����������.
class MyException : public std::exception {
protected:
    std::string err;
public:
    MyException(const std::string);
    virtual const char* what() const override;
};

//� ���������:
//throw MyException(<������>);
//catch (const MyException& ex) { std::cout << ex.what() << std::endl; }

