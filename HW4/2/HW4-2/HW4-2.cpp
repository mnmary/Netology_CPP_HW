// HW4-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
    std::string gorod;
    std::string ulica;
    int dom;
    int kvartira;


public:
    std::string getAddressAsString()
    {
        return (gorod + ", " + ulica + ", " + std::to_string(dom) + ", " + std::to_string(kvartira) + "\n");
    }
    std::string getGorod()
    {
        return gorod;
    }
    Address(std::string gorod, std::string ulica, int dom, int kvartira)
    {
        this->gorod = gorod;
        this->ulica = ulica;
        this->dom = dom;
        this->kvartira = kvartira;
    }
};

bool Swap(std::string s1, std::string s2, int pos)
{
    if (s1[pos] > s2[pos])
        return true;
    if (s1 == s2)
        return false;
    if (s1[pos] == s2[pos])
        return Swap(s1, s2, pos + 1);
    return false;
}


int main()
{
    int recordCount, recordNum;
    std::string gorod;
    std::string ulica;
    int dom;
    int kvartira;

    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile("in.txt");
    if (inputFile.is_open())
    {
        inputFile >> recordCount;

        std::cout << recordCount << std::endl;

        Address** arrAddress = new Address * [recordCount];

        recordNum = 0;
        while (!inputFile.eof())
        {
            inputFile >> gorod >> ulica >> dom >> kvartira;  //address

            arrAddress[recordNum] = new Address(gorod, ulica, dom, kvartira); //new object
            std::cout << arrAddress[recordNum]->getAddressAsString();//as ptr!!!
            recordNum++;
        }
        inputFile.close();
        //sort
        bool changeFlag = false;
        int i = 0;
        int j = 0;
        Address* tempAddress;

        while (i < recordCount - 1)
        {
            changeFlag = false;
            j = i + 1;
            while (j < recordCount)
            {
                if (Swap(arrAddress[i]->getGorod(), arrAddress[j]->getGorod(), 0))
                {
                    tempAddress = arrAddress[i];
                    arrAddress[i] = arrAddress[j];
                    arrAddress[j] = tempAddress;
                    changeFlag = true;
                }
                j++;
            }
            if (changeFlag)
                i = 0;
            else
                i++;
        }
        
        //
        std::ofstream outFile;
        outFile.open("out.txt");
        outFile << recordCount << std::endl;
        for (int i = 0; i != recordCount; i++)
        {
            outFile << arrAddress[i]->getAddressAsString();
            //std::cout << arrAddress[i]->getAddressAsString();//as ptr!!!
        }
        outFile.close();
        //
        for (int i = 0; i != recordCount; ++i)
        {
            delete arrAddress[i];
        }
        delete[] arrAddress;

    }
    return 0;
}



