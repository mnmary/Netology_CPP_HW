// HW2-1-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct adres
{
    int indeks;
    std::string gorod;
    std::string uliza;
    int dom;
    int kvartira;
};

void printAdres(adres a)
{
    std::cout << "Город: " << a.gorod << std::endl << "Улица:" << a.uliza << std::endl << "Дом:" << a.dom << std::endl << "Квартира:" << a.kvartira << std::endl << "Индекс:" << a.indeks << std::endl;
    std::cout << std::endl;

}
int main()
{
    setlocale(LC_ALL, "Russian");

    adres adr1;
    adr1.indeks = 112233;
    adr1.gorod = "Рязань";
    adr1.uliza = "Ленина";
    adr1.dom = 5;
    adr1.kvartira = 1;

    adres adr2;
    adr2.indeks = 112211;
    adr2.gorod = "Рязань";
    adr2.uliza = "Гагарина";
    adr2.dom = 50;
    adr2.kvartira = 11;

    printAdres(adr1);
    printAdres(adr2);
    return 0;
}
