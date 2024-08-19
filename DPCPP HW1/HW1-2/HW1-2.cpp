// HW1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "sql_query_builder.h"

int main()
{
    /*
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    query_builder.BuildQuery();
    */

    
    SqlSelectQueryBuilder query_builder1;

    std::vector<std::string> columns{};
    std::map<std::string, std::string> where{};

    columns.push_back("name");
    columns.push_back("phone");
    query_builder1.AddColumns(columns);
    query_builder1.AddFrom("students");
    where.emplace("id", "42");
    where.emplace("name", "John");
    query_builder1.AddWhere(where);

    query_builder1.BuildQuery();
    
}

