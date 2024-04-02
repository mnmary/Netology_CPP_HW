// AlgoHW6-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int simple_string_hash(std::string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        result = result + s[i];
    }
    return result;
}

int find_substring_light_rabin_karp(std::string substr, std::string str)
{
    int temp_hash = 0, flag = 0;
    std::string temp_str;


    int hash_sub = simple_string_hash(substr);

    for (int i = 0; i < str.length()- substr.length()+1; i++)
    {
        if (i == 0)
        {
            temp_str = str.substr(0, substr.length());
            temp_hash = simple_string_hash(temp_str);
        }
        else
        {
            temp_hash = temp_hash - str[i - 1];
            temp_hash = temp_hash + str[i - 1 + substr.length()];
        }
        if (hash_sub != temp_hash)
        {
                //не подходит
                continue;
        }
        else
        {
                flag = 1;
                for (int j = 0; j < substr.length(); j++)
                {
                    if (substr[j] != str[i + j])
                    {
                        //не подходит
                        flag = 0;
                        break;
                    }
                }

                if (flag)
                {
                    //подошел
                    return i;
                }
        }
    }

    return -1;
}

int main()
{
    std::string cmd;
    std::string str;
    int result = 0;

    setlocale(LC_ALL, "Rus");

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;

    while (true)
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> cmd;
        if (cmd == "exit") break;
        result = find_substring_light_rabin_karp(cmd, str);
        if (result >= 0)
        {
            std::cout << "Подстрока " << cmd << " найдена по индексу " << result << std::endl;
        }
        else
        {
            std::cout << "Подстрока " << cmd << " не найдена" << std::endl;
        }
    }
    result = find_substring_light_rabin_karp(cmd, str);
    if (result >= 0)
    {
        std::cout << "Подстрока " << cmd << " найдена по индексу " << result << std::endl;
    }
    else
    {
        std::cout << "Подстрока " << cmd << " не найдена" << std::endl;
    }
}
