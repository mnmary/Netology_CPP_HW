#pragma once
#include <iostream>
#include <map>
#include <vector>

struct Data
{
    std::string from_table;
    std::string columns;
    std::string where;
    std::string query;
};

bool is_empty(const std::string& str)
{
    return str.empty();
}

class SqlSelectQueryBuilder
{
public:
    SqlSelectQueryBuilder()
    {
        std::cout << "create a SQL builder\n";
    }

    void BuildQuery() noexcept
    {
        data.query = "";
        data.query += "SELECT ";
        if (is_empty(data.columns))
        {
            data.columns = "*";
        }
        data.query += data.columns;
        data.query += " FROM ";
        data.query += data.from_table;
        if (!is_empty(data.where))
        {
            data.query += " WHERE ";
            data.query += data.where;
            data.query += ";";
        }
        std::cout << "QUERY: " << data.query << std::endl;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) noexcept
    {
        if (is_empty(data.where))
        {
            data.where = column + " = " + value;
        }
        else
        {
            data.where += " AND " + column + " = " + value;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
    {
        for (auto& item : kv)
        {
            if (is_empty(data.where))
            {
                data.where = item.first + " = " + item.second;
            }
            else
            {
                data.where += " AND " + item.first + " = " + item.second;
            }
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept
    {
        if (is_empty(data.columns))
        {
            data.columns = column;
        }
        else
        {
            data.columns += ", " + column;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept
    {
        for (auto& item : columns)
        {
            if (is_empty(data.columns))
            {
                data.columns = item;
            }
            else
            {
                data.columns += ", " + item;
            }
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& from) noexcept
    {
        data.from_table = from;
        return *this;
    }


private:
    Data data;
};
