#pragma once
#include <iostream>
#include <stdexcept>

	class INI_Exception : public std::exception
	{
	public:
		INI_Exception(const char* message);
		const char* what() const throw();
	private:
		std::string message;
	};
