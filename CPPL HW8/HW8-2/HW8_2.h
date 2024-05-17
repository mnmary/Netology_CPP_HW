#pragma once
#include <iostream>

namespace HW8_2
{
	template <class T>
	void print_container(const T& container)
	{
		for (auto iterator = container.begin(); iterator != container.end(); ++iterator)
		{
			std::cout << *iterator << " ";
		}
		std::cout << std::endl;
	}
}
