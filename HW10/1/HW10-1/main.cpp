#include <iostream>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	std::string FIO;
	std::cout << "Введите имя: ";
	std::cin >> FIO;
	std::cout << "Здравствуйте, " << FIO << "!" << std::endl;
	system("pause");
	return 0;
}