// HW2-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

HANDLE hStdOut;
std::mutex mutex;
COORD point;

void drawProgress( int tNum, int level)
{
    mutex.lock();
    auto tId = std::this_thread::get_id();
    auto timerBeg = std::chrono::high_resolution_clock::now();
     mutex.unlock();

    for (int i = 0; i < level; i++)
    {
        mutex.lock();
        point.X = i;
        point.Y = tNum * 2;
        SetConsoleCursorPosition(hStdOut, point);
        std::cout << char(219);
        mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    mutex.lock();
    auto timerEnd = std::chrono::high_resolution_clock::now();
    auto timeElapsed = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> > >(timerEnd - timerBeg).count();
    point.X = level+5;
    point.Y = tNum * 2;
    SetConsoleCursorPosition(hStdOut, point);
    std::cout << "  #" << tNum + 1 << "  ID = " << tId << "   Timer = " << timeElapsed << std::endl;
    mutex.unlock();
}

int main()
{
    int tCount{ 4 };
    int pLen{ 20 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    std::vector<std::thread> vThread(tCount);

    for (int i = 0; i < tCount; i++)
    {
        vThread[i] = std::thread(drawProgress, i, pLen);
    }
    for (auto& i : vThread)
    {
        i.join();
    }
    point.X = 0;
    point.Y = tCount * 2;
    SetConsoleCursorPosition(hStdOut, point);


 }
