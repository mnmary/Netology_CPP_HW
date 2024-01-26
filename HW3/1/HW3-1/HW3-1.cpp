// HW3-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
class Calculator
{
private:
	double num1;
	double num2;
public:
	double add()
	{
		return num1 + num2;
	}
	double multiply()
	{
		return num1 * num2;
	}
	double subtract_1_2()
	{
		return num1 - num2;
	}
	double subtract_2_1()
	{
		return num2 - num1;
	}
	double divide_1_2()
	{
		return num1 / num2;
	}
	double divide_2_1()
	{
		return num2 / num1;
	}
	//метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. 
	// Возвращает true, если установка произошла успешно, в обратном случае false
	bool set_num1(double num1)
	{
		if (num1 == 0) return false;
		this->num1 = num1;
		return true;
	}
	bool set_num2(double num2)
	{
		if (num2 == 0) return false;
		this->num2 = num2;
		return true;
	}

};
#include <iostream>

int main()
{
	double num1;
	double num2;
	bool res;

	Calculator myCalculator;
	
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		do
		{
			//--
			std::cout << "Введите num1: ";
			std::cin >> num1;
			res = myCalculator.set_num1(num1);
			if (!res)
			{
				std::cout << "Неверный ввод!\n";
			}
		} while (!res);
		do
		{
			//--
			std::cout << "Введите num2: ";
			std::cin >> num2;
			res = myCalculator.set_num2(num2);
			if (!res)
			{
				std::cout << "Неверный ввод!\n";
			}
		} while (!res);
		//
		std::cout << "num1 + num2 = " << myCalculator.add() << std::endl;
		std::cout << "num1 - num2 = " << myCalculator.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << myCalculator.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << myCalculator.multiply() << std::endl;
		std::cout << "num1 / num2 = " << myCalculator.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << myCalculator.divide_2_1() << std::endl;


	}//while true
}//int main



