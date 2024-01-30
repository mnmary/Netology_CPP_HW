// HW4-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
        return (gorod+", "+ulica+", "+std::to_string(dom)+", "+std::to_string(kvartira)+"\n");
    }
    Address(std::string gorod, std::string ulica, int dom, int kvartira)
    {
        this->gorod = gorod;
        this->ulica = ulica;
        this->dom = dom;
        this->kvartira = kvartira;
    }
};



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

        Address** arrAddress = new Address* [recordCount];

        recordNum = 0;
        while (!inputFile.eof())
        {
            inputFile >> gorod >> ulica >> dom >> kvartira;  //address
            //Address adr(gorod, ulica, dom, kvartira);
            arrAddress[recordNum] = new Address(gorod, ulica, dom, kvartira); //new object
            std::cout << arrAddress[recordNum]->getAddressAsString();//as ptr!!!
            recordNum++;
        }
        inputFile.close();
        
        //
        std::ofstream outFile;
        outFile.open("out.txt");
        outFile << recordCount << std::endl;
        for (int i = 0; i != recordCount; i++)
        {
            outFile << arrAddress[recordCount-i-1]->getAddressAsString();//reverse!!
        }
        outFile.close();
        //
        for (int i = 0; i != recordCount; ++i)
        {
            delete arrAddress[i];
        }
        delete[] arrAddress;

    }
}


