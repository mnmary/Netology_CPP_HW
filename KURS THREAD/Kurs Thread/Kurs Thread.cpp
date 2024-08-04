// Kurs Thread.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <atomic>
#include <condition_variable>
#include <functional>
#include <list>
#include <mutex>
#include <thread>
#include <iostream>
#include "Thread_Pool.h"



void doWork1()
{
    std::cout << "work id: " << std::this_thread::get_id() << std::endl;
    std::cout << __FUNCTION__ << std::endl;
}
void doWork2()
{
    std::cout << "work id: " << std::this_thread::get_id() << std::endl;
    std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    // number of task to exec
    const int cntCycle = 10;
    Thread_Pool pool;
    std::vector<std::function<void()> >vWorks{ doWork1,doWork2 };
    for (int i = 0; i < cntCycle; i++)
    {
        pool.submit(vWorks);
    }
    
    return 0;
}