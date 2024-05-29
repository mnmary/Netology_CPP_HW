#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "INI_Exception.h"

namespace INI_PARSER
{
	using myINI = std::map<std::string, std::map<std::string, std::string> >;
	using myINI_item = std::map<std::string, std::string>;

	class ini_parser
	{
	private:
		myINI _values;
		std::string _fileName;

		//trim
		void trim(std::string& s);
	public:
		ini_parser(const std::string& fileName);
		~ini_parser() = default;

		void print();

		template <typename T>
		T get_value(const std::string& sectionAndItem) const
		{
			//Вам нужно реализовать класс парсера INI - файлов, который предоставляет для пользователя одну шаблонную функцию, позволяющую получить значение переменной в определённой секции.
			size_t flag = sectionAndItem.find('.');
			if (flag == std::string::npos)
			{
				std::string a = "Incorrect format of Section.Item: ";
				a.append(sectionAndItem);
				throw INI_Exception(a.data());
			}
			//делаем расшифровку параметров поиска
			std::string section = sectionAndItem.substr(0, flag);
			std::string key = sectionAndItem.substr(flag + 1);

			//ищем секцию
			auto it = _values.find(section);
			if (it == _values.end())
			{
				std::string a = "Section do not exists: ";
				a.append(section);
				throw INI_Exception(a.data());
			}
			//ищем ключ в секции
			auto item_it = it->second.find(key);
			if (item_it == it->second.end())
			{
				//*Если искомого значения переменной нет, нужно вывести подсказку для пользователя — названия других переменных из этой секции.Возможно, пользователь опечатался.

				std::string result{ "\nThis is available items:\n" };
				auto it = _values.find(section);

				for (myINI_item::const_iterator eptr = it->second.begin(); eptr != it->second.end(); eptr++)
				{
					result = result + "- " + eptr->first + "\n";
				}
				std::string a = "Item do not exists: ";
				a.append(sectionAndItem);
				a.append(result);
				throw INI_Exception(a.data());
			}


			if (_values.at(section).at(key) == "")
			{
				//значение пустое
				std::string a = "Value do not exists: ";
				a.append(_values.at(section).at(key).data());
				throw INI_Exception(a.data());
			}
			//конвертируем в нужный тип через стрим
			std::istringstream iss(_values.at(section).at(key));

			T value;
			if (!(iss >> value))
			{
				std::string a = "Error of convert value: ";
				a.append(_values.at(section).at(key).data());
				throw INI_Exception(a.data());
			}
			return value;
		}

	};
}
