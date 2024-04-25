#pragma once
class smart_array
{
private:
	int* array;   //динамический массив 
	int cnt = 0;	//количество элементов
	int size = 0;	//размер массива
public:
	smart_array();	//конструктор без параметров
	smart_array(int size);	//конструктор с параметрами
	~smart_array();             // деструктор
	void add_element(int value);	//добавить элемент в конец массива
	int get_element(int index);	//вернуть значение элемента с индексом 0..количество элементов-1
	smart_array& operator=(const smart_array& other);	//оператор присваивания( на случай если присваивание будет типа  a = b = c = ...
};

