#pragma once
#include <iostream>
namespace HW10_3
{
    template <class T>
    class MyUnique_Ptr
    {
    private:
        T* _ptr{ nullptr };
    public:
        explicit MyUnique_Ptr(T* ptr) : _ptr{ ptr }
        {
            std::cout << "Constructor "<< std::endl;
        }

        ~MyUnique_Ptr()
        {
            std::cout << "Destructor " << std::endl;
            _ptr = nullptr;
            delete _ptr;
        }

        MyUnique_Ptr(const MyUnique_Ptr& other) = delete;
        MyUnique_Ptr& operator = (const MyUnique_Ptr& other) = delete;

        T& operator *() const
        {
            std::cout << "Operator * " << std::endl;
            return *_ptr;
        }

        T* release()
        {
            std::cout << "release " << std::endl;

            T* newPtr(_ptr);
            _ptr = nullptr;

            return newPtr;
        }

     };
}
