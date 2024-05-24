// HW11-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "big_integer.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	auto number1 = big_integer("1102");
	std::cout << "Число 1: " << number1;
	auto number2 = big_integer("11");
	std::cout << "Число 2: " << number2;
	auto result = number1 + number2;
	std::cout << "Сумма: " << result;
	result = number1 * number2;
	std::cout << "Произведение: " << result;
	
	return 0;
}

