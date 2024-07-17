// HW1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void calcSum(double& sum, const std::vector<int> v1, const std::vector<int> v2)
{
    for (int i = 0; i < v1.size(); ++i)
    {
        sum += v1.at(i) + v2.at(i);
    }
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> vThreadCnt{ 1,2,4,8,16 };
    std::vector<int> vSize{ 1'000, 10'000, 100'000, 1'000'000 };

    std::cout << "Core count: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Threads   1 000    10 000   100 000  1 000 000" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    for (int t : vThreadCnt)
    {
        //-------------
        std::cout << t << " threads      ";

        for (int s : vSize)
        {
            v1.resize(s);//!!!
            v2.resize(s);//!!
            for (int i = 0; i < s; i++)
            {
                v1[i] = rand();
                v2[i] = rand();
            }

            double vSum = 0;
            std::vector<std::thread> vThread;
            for (int cntT = 0; cntT < t; cntT++)
            {
                vThread.push_back(std::thread(calcSum, std::ref(vSum), v1, v2));
            }

            auto thrStart = std::chrono::high_resolution_clock::now();
            for (auto& t : vThread)
            {
                t.join();
            }
            auto thrStop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> thrTime = thrStop - thrStart;
            std::cout << thrTime.count() / 1000 << "s   ";
        }
        std::cout << std::endl;
        //-----------
    }
    return 0;
}
