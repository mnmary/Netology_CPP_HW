#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "ini_parser.h"
#include "INI_Exception.h"

namespace INI_PARSER
{
	void ini_parser::trim(std::string& s)
	{
		//ltrim
		s.erase(0, s.find_first_not_of(" \t"));
		//rtrim
		s.erase(s.find_last_not_of(" \t") + 1);
	}

	ini_parser::ini_parser(const std::string& fileName) : _fileName{ fileName }
	{
		int strNum{ 0 };
		std::string str{ "" };
		std::string sectionName{ "" };

		//std::cout << "create a INI parser, file: " << fileName << std::endl;
		//read file
		std::ifstream input(_fileName);
		if (!input)
		{
			std::string a = "Ошибка открытия файла ";
			a.append(_fileName);
			throw INI_Exception(a.data());
		}

		while (std::getline(input, str)) // Так можно считывать до тех пор пока считывается.
		{
			strNum++;
			trim(str);
			if (!str.empty())
			{
				//*Если файл содержит некорректный синтаксис, нужно указать в исключении, на какой строке встретилась проблема.

				//строка не пустая
				trim(str);

				//if comment					
				if (str[0] == ';')
				{
					//*Строка комментариев.
					//Имеет формат : `; строка комментариев `. <br / > Парсер должен игнорировать такие строки, с ними ничего делать не нужно.
				}
				else if (str[0] == '[')
				{
					//*Строка имени секции — обозначает имя новой секции переменных.
					//Имеет формат : `[имя_секции] `. <br / > Пробелы и символы табуляции, стоящие до открывающей и после закрывающей скобки, игнорируются.
					if (str.back() == ']')
					{
						//section
						sectionName = str.substr(1, str.size() - 2);
						_values[sectionName];	//делаем это на случай пустой секции(нет ключей)
					}
					else
					{
						std::string a = "Section error in line ";
						a.append(std::to_string(strNum));
						throw INI_Exception(a.data());
					}
				}
				else
				{
					//*Строка задания переменной — задаёт значение переменной.
					//Имеет формат : ` название_переменной = значение_переменной `. <br / > Количество пробелов между символами равенства может быть произвольным.
					//Для простоты будем считать, что значения могут быть либо строкой, либо числом.Несколько значений не допускается.						
					std::istringstream iss(str);
					std::string item{ "" }, value{ "" };

					std::getline(iss, item, '=');
					std::getline(iss, value);

					trim(item);
					if (item == "")
					{
						std::string a = "Item error in line ";
						a.append(std::to_string(strNum));
						throw INI_Exception(a.data());
					}

					trim(value);

					//ищем комментарии в конце строки
					size_t flag = value.find(';');
					if (flag != std::string::npos)
					{
						value = value.substr(0, flag - 1);
						trim(value);
					}

					//запоминаем значение в ТЕКСТОВОМ формате
					_values[sectionName][item] = value;

				}
			}
		}
		input.close();

	}
	void ini_parser::print()
	{
		std::cout << "INI-file" << std::endl;
		for (myINI::const_iterator ptr = _values.begin(); ptr != _values.end(); ptr++)
		{
			std::cout << "[" << ptr->first << "]" << std::endl;
			for (myINI_item::const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end(); eptr++)
			{
				std::cout << eptr->first << " : " << eptr->second << std::endl;

			}

		}

	}

}