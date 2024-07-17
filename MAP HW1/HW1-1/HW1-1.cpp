// HW1-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <functional>
int clientNum{ 0 };
int maxClients{ 100 };

void t1()
{
    while (clientNum < maxClients)
    {
        clientNum++;
        std::cout << "thread1: clientNum = " << clientNum << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void t2()
{
    while (true)
    {
        if (clientNum > 0)
        {
            clientNum--;
            std::cout << "thread2: clientNum = " << clientNum << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else
        {
            std::cout << "thread2: stop";
            break;
        }
    }
}

int main()
{
    std::thread thread1(t1);
    std::thread thread2(t2);

    thread1.join();
    thread2.join();

    return 0;
}


