#include "smart_array.h"
#include <exception>
smart_array::smart_array()	//����������� ��� ����������
{
	this->size = 0;
	this->cnt = 0;
}
smart_array::smart_array(int size)	//����������� � �����������
{
	this->array = new int[size];
	this->size = size;
}
smart_array::~smart_array()             // ����������
{
	delete[] array;
}
void smart_array::add_element(int value)	//�������� ������� � ����� �������
{
	if (this->cnt < this->size)
	{
		this->array[cnt++] = value;
	}
	else
	{
		throw std::exception("������ �����!");
	}
}
int smart_array::get_element(int index)	//������� �������� �������� � �������� 0..���������� ���������-1
{
	if (index <= this->cnt-1)
	{
		return this->array[index];
	};
	throw std::exception("������������ ������ ��������!");
}

smart_array& smart_array::operator=(const smart_array& other)	//�������� ������������( �� ������ ���� ������������ ����� ����  a = b = c = ...
//���� ������������ ���� � = b, �� ����� void ��� ����������� ��������
{
	if (this == &other) return *this; // ���� ��� ���� �����������: arr = arr;

	//�������� ���������
	this->size = other.size;
	this->cnt = other.cnt;

	if (this->array != nullptr)
	{
		delete[] this->array;	//������� ������
	}
	//������� ������ � ������ ���������
	this->array = new int[this->size];

	//�������� ����������
	for (int i = 0; i < other.size; i++)
	{
		this->array[i] = other.array[i];
	}
	//���������� ����
	return *this;
}
