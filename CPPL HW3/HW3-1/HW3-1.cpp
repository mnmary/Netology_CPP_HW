// HW3-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "smart_array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(16);
		std::cout << arr.get_element(0) << std::endl;

		//smart_array b;
		//b = arr;
		//std::cout << b.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}


