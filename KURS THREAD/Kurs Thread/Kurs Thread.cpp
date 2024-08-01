// Kurs Thread.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <functional>
#include <queue>
#include <chrono>
using namespace std::chrono_literals;

std::mutex mutex, mutex1;

void work()
{
    mutex1.lock();
    auto tId = std::this_thread::get_id();
    std::cout << tId<< ": Function: " << __FUNCTION__ << " has done her work!" << std::endl;
    mutex1.unlock();
}

std::queue<std::function<void()>> workQueue;

void fillWorkQueue()
{
    for (int i = 0; i < 16; i++)
    {
        mutex.lock();
        workQueue.push(work);
        std::cout << "PUSH WORK " << i+1 << std::endl;
        mutex.unlock();
        std::this_thread::sleep_for(1s);
    }
}

std::function<void()> getWork()
{
    std::function<void()> w;
    if (!workQueue.empty())
        {
            w = workQueue.front();
            workQueue.pop();
            std::cout << "POP WORK" << std::endl;
        }
    return w;
}

int main()
{
    std::thread thread1(fillWorkQueue);//заполоняем очередь работ

    const int coreCount = std::thread::hardware_concurrency();//определяем количество ядер
    
    std::vector<std::thread> vThread;//вектор потоков

    for (int i = 0; i < coreCount; i++)
    {
        std::function<void()> w = getWork();//берем из очереди очередную работу
        vThread.push_back(std::thread(w));//создаем поток с работой и добавляем в вектор
    }

    thread1.join();//ждем завершения заполнения

    for (auto& i:vThread)
    {
        i.join();//ждем завершения потоков с работой
    }
    return 0;
}