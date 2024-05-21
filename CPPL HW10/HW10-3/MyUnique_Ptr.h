#pragma once
#include <iostream>
namespace HW10_3
{
    template <class T>
    class MyUnique_Ptr
    {
    private:
        T* _ptr{ nullptr };
        std::string _name{ "" };
    public:
        MyUnique_Ptr(T* ptr, const std::string& name) : _ptr{ ptr }, _name{ name }
        {
            std::cout << "Constructor " << _name << std::endl;
        }

        ~MyUnique_Ptr()
        {
            std::cout << "Destructor " << _name << std::endl;
            _ptr = nullptr;
        }

        MyUnique_Ptr(const MyUnique_Ptr& other) = delete;
        MyUnique_Ptr& operator = (const MyUnique_Ptr& other) = delete;

        T& operator *() const
        {
            std::cout << "Operator * " << _name << std::endl;

            if (_ptr)
            {
                return *_ptr;
            }
            else
            {
                throw("Error of pointer");
            };
        }

        T* release()
        {
            std::cout << "release " << _name << std::endl;

            T* newPtr(_ptr);
            _ptr = nullptr;

            return newPtr;
        }

        T* getPtr() const
        {
            return _ptr;
        }
    };
}
