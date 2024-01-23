// HW2-1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct deposits
{
    int num;
    std::string fio;
    double balance;
};

void printDep(deposits* d)
{
    std::cout << "Ваш счет: " << d->fio << ", " << d->num << ", " << d->balance << std::endl;
}
void changeDep(deposits* d, double newBalance)
{
    d->balance = newBalance;
}
int main()
{

    deposits dep;
    double newBalance;

    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер счета: ";
    std::cin >> dep.num;
    std::cout << "Введите имя владельца: ";
    std::cin >> dep.fio;
    std::cout << "Введите баланс счета: ";
    std::cin >> dep.balance;
    printDep(&dep);

    std::cout << "Введите новый баланс счета: ";
    std::cin >> newBalance;
    changeDep(&dep, newBalance);
    printDep(&dep);
    return 0;
}
