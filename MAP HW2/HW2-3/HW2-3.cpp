// HW2-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>
#include <mutex>

class Data
{
private:
    int value;
public:
    std::mutex mutex;
    Data(int value) : value{ value }
    {

    }
    void setValue(int value)
    {
        this->value = value;
    }
    int getValue()
    {
        return this->value;
    }
};


void swapLock(Data& d1, Data& d2)
{
    std::lock(d1.mutex, d2.mutex);

    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "Id: " << std::this_thread::get_id() << " (lock)" << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value2 = " << d2.getValue() << ";" << std::endl;

    d1.mutex.unlock();
    d2.mutex.unlock();
}

void swapScopedLock(Data& d1, Data& d2)
{
    std::scoped_lock lock(d1.mutex, d2.mutex);

    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "Id: " << std::this_thread::get_id() << " (Scoped)" << std::endl;
    std::cout << "value1 = " << d1.getValue() << std::endl;
    std::cout << "value2 = " << d2.getValue() << std::endl;
}

void swapUniqueLock(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> lock1(d1.mutex, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.mutex, std::defer_lock);
    lock1.lock();
    lock2.lock();
    //swap
    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "Id: " << std::this_thread::get_id() << " (unique)" << std::endl;
    std::cout << "value1 = " << d1.getValue() << std::endl;
    std::cout << "value2 = " << d2.getValue() << std::endl;
    lock1.unlock();
    lock2.unlock();
}
int main()
{
    Data d1(123);
    Data d2(45);

    std::thread t1(swapLock, std::ref(d1), std::ref(d2));
    std::thread t2(swapScopedLock, std::ref(d1), std::ref(d2));
    std::thread t3(swapUniqueLock, std::ref(d1), std::ref(d2));

    std::cout << "ID(main thread): " << std::this_thread::get_id() << std::endl;

    std::cout << "Values before:" << std::endl;
    std::cout << "value1 = " << d1.getValue() << std::endl;
    std::cout << "value2 = " << d2.getValue() << std::endl;

    t1.join();
    t2.join();
    t3.join();

    return 0;
}