﻿// HW3-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void add(int& val)
{
	val++;
}

template<typename Iterator>
void parallel_for_each(Iterator first, Iterator last)
{
	//vector len
	auto length = std::distance(first, last);
	//divider
	unsigned long const max_chunk_size = 2;
	if (length <= max_chunk_size)
	{
		//increment
		std::for_each(first, last, add);
		//nothing
	}
	else
	{
		//divide
		Iterator mid_point = first;
		std::advance(mid_point, length / 2);
		//future
		auto res = std::async(parallel_for_each<Iterator>, first, mid_point);
		//recursive
		parallel_for_each(mid_point, last);
		//wait
		res.get();
	}
}

void print_vector(std::vector<int>& v)
{
	for (auto v1 : v)
	{
		std::cout << v1 << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v {9,1,5,6,4,3};
	std::cout << "Before: ";
	print_vector(v);

	parallel_for_each(v.begin(), v.end());

	std::cout << "After: ";
	print_vector(v);

	return 0;
}
