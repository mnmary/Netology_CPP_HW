// Kurs_INI_Parser.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ini_parser.h"
#include "INI_Exception.h"

//Курсовой проект — простой парсер файлов формата INI.
int main()
{
	setlocale(LC_ALL, "Rus");
	INI_PARSER::ini_parser a("test.ini");
	try
	{
		std::cout << "Section1.Mode1:" << std::fixed << a.get_value < double > ("Section1.Mode1") << std::endl;
	}
	catch (const INI_Exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	//a.print();

	return 0;
}

