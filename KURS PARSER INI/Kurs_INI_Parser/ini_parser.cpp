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
			std::string a = "������ �������� ����� ";
			a.append(_fileName);
			throw INI_Exception(a.data());
		}

		while (std::getline(input, str)) // ��� ����� ��������� �� ��� ��� ���� �����������.
		{
			strNum++;
			trim(str);
			if (!str.empty())
			{
				//*���� ���� �������� ������������ ���������, ����� ������� � ����������, �� ����� ������ ����������� ��������.

				//������ �� ������
				trim(str);

				//if comment					
				if (str[0] == ';')
				{
					//*������ ������������.
					//����� ������ : `; ������ ������������ `. <br / > ������ ������ ������������ ����� ������, � ���� ������ ������ �� �����.
				}
				else if (str[0] == '[')
				{
					//*������ ����� ������ � ���������� ��� ����� ������ ����������.
					//����� ������ : `[���_������] `. <br / > ������� � ������� ���������, ������� �� ����������� � ����� ����������� ������, ������������.
					if (str.back() == ']')
					{
						//section
						sectionName = str.substr(1, str.size() - 2);
						_values[sectionName];	//������ ��� �� ������ ������ ������(��� ������)
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
					//*������ ������� ���������� � ����� �������� ����������.
					//����� ������ : ` ��������_���������� = ��������_���������� `. <br / > ���������� �������� ����� ��������� ��������� ����� ���� ������������.
					//��� �������� ����� �������, ��� �������� ����� ���� ���� �������, ���� ������.��������� �������� �� �����������.						
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

					//���� ����������� � ����� ������
					size_t flag = value.find(';');
					if (flag != std::string::npos)
					{
						value = value.substr(0, flag - 1);
						trim(value);
					}

					//���������� �������� � ��������� �������
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