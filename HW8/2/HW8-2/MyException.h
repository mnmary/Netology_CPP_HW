#pragma once
#include <stdexcept>
#include <iostream>

class MyException : public std::domain_error {

public:
    MyException(const std::string);//constructor
};


