#include "MyException.h"
MyException::MyException(const std::string err)
{
    this->err = err;
}
const char* MyException::what() const 
{
    const char* c_err = err.c_str();
    return(c_err);
}
