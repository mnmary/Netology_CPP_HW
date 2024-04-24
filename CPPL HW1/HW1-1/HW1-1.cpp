// HW1-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

void printVector(std::vector<int> &v)
{
	for (int vv : v)
	{
		std::cout << vv << " ";
	};
	std::cout << std::endl;
}
int main()
{
	setlocale(LC_ALL, "rus");

	std::vector<int> v{ 4, 7, 9, 14, 12 };
	/*
	//для обычного вызова
	auto lambda
	{
		[&v]()
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i] = v[i] * 3;
			}

		}
	};
	*/
	std::cout << "Входные данные: ";
	printVector(v);

	//обычный вызов лямбда-функции
	//lambda();

	//немедленный вызов лямбда-функции
	[&v]()
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] % 2 != 0)
				{
					v[i] = v[i] * 3;
				}
			}

		}();	//!!

	std::cout << "Выходные данные: ";
	printVector(v);


}

