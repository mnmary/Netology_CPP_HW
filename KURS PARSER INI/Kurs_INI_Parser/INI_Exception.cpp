#include <stdexcept>
#include "INI_Exception.h"
	INI_Exception::INI_Exception(const char* message) : message(message) 
	{
		//nothing
	}
	const char* INI_Exception::what() const throw()
	{
		return message.c_str();
	}
