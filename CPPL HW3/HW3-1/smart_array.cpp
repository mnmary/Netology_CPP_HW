#include "smart_array.h"
#include <exception>
smart_array::smart_array()	//конструктор без параметров
{
	this->size = 0;
	this->cnt = 0;
}
smart_array::smart_array(int size)	//конструктор с параметрами
{
	this->array = new int[size];
	this->size = size;
}
smart_array::~smart_array()             // деструктор
{
	delete[] array;
}
void smart_array::add_element(int value)	//добавить элемент в конец массива
{
	if (this->cnt < this->size)
	{
		this->array[cnt++] = value;
	}
	else
	{
		throw std::exception("Массив полон!");
	}
}
int smart_array::get_element(int index)	//вернуть значение элемента с индексом 0..количество элементов-1
{
	if (index <= this->cnt-1)
	{
		return this->array[index];
	};
	throw std::exception("Некорректный индекс элемента!");
}

smart_array& smart_array::operator=(const smart_array& other)	//оператор присваивания( на случай если присваивание будет типа  a = b = c = ...
//если присваивание типа а = b, то нужен void без возвращения значения
{
	if (this == &other) return *this; // если сам себе присваивает: arr = arr;

	//копируем параметры
	this->size = other.size;
	this->cnt = other.cnt;

	if (this->array != nullptr)
	{
		delete[] this->array;	//удаляем массив
	}
	//создаем массив с новыми размерами
	this->array = new int[this->size];

	//копируем содержимое
	for (int i = 0; i < other.size; i++)
	{
		this->array[i] = other.array[i];
	}
	//возвращаем себя
	return *this;
}
