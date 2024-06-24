#include <iostream>
#include "MyClientBase.h"
MyClientBase::MyClientBase(const std::string& connectionString) :_connectionString{ connectionString } {}

void MyClientBase::createTable()
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);
        transact.exec("CREATE TABLE IF NOT EXISTS clients(id SERIAL PRIMARY KEY, name VARCHAR(500), surname VARCHAR(500), email VARCHAR(100) UNIQUE);"
            "CREATE TABLE IF NOT EXISTS phones(id SERIAL PRIMARY KEY, client_id INT REFERENCES clients(id), phone VARCHAR(50) UNIQUE);");
        transact.commit();

        std::cout << "New table action" << std::endl;
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }

}
void MyClientBase::createClient(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone)
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("INSERT INTO clients (name, surname, email) VALUES ($1, $2, $3) RETURNING id", name, surname, email);//return new record ID
        if (!res.empty())
        {
            int a = res[0][0].as<int>();
            transact.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2) RETURNING id", a, phone);

            transact.commit();
            std::cout << "New client action" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }
}
void MyClientBase::addPhone(const std::string& name, const std::string& phone)
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("SELECT id from clients where name=$1", name);//get ID
        if (!res.empty())
        {
            int a = res[0][0].as<int>();
            transact.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2) RETURNING id", a, phone);

            transact.commit();
            std::cout << "New phone action" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }

}

void MyClientBase::updateClients(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail)
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("SELECT id FROM clients WHERE email = $1", email);//get ID
        if (!res.empty())
        {
            int a = res[0][0].as<int>();
            transact.exec_params("UPDATE clients SET name=$2, surname=$3, email=$4 WHERE id = $1", a, newName, newSurname, newEmail);

            transact.commit();
            std::cout << "Update client action" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

void MyClientBase::deletePhone(const std::string& email, const std::string& phone)
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("SELECT id FROM clients WHERE email = $1", email);//get ID
        if (!res.empty())
        {
            int a = res[0][0].as<int>();
            transact.exec_params("DELETE FROM phones WHERE client_id = $1 AND phone = $2", a, phone);

            transact.commit();
            std::cout << "Delete phone action" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

void MyClientBase::deleteClient(const std::string& email)
{
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("SELECT id FROM clients WHERE email = $1", email);//get ID
        if (!res.empty())
        {
            int a = res[0][0].as<int>();
            transact.exec_params("DELETE FROM phones WHERE client_id = $1", a);//!!! link!!!
            transact.exec_params("DELETE FROM clients WHERE id = $1", a);

            transact.commit();
            std::cout << "Delete client action" << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }
}
std::vector<MyClient> MyClientBase::findClients(const std::string& searchString)
{
    std::vector<MyClient> clientList;
    try
    {
        pqxx::connection conn(_connectionString);
        pqxx::work transact(conn);

        pqxx::result res = transact.exec_params("SELECT * FROM clients LEFT JOIN phones ON Phones.client_id = clients.id"
            " WHERE clients.name = $1 OR clients.surname=$1 OR clients.email = $1 OR phones.phone = $1", searchString);
        if (!res.empty())
        {
            for (auto row : res)
            {
                MyClient client;
                client.name = row["name"].as<std::string>();
                client.surname = row["surname"].as<std::string>();
                client.email = row["email"].as<std::string>();
                client.phone = row["phone"].as<std::string>();
                clientList.push_back(client);
            }
        }
        std::cout << "Find client action" << std::endl;
        return clientList;
    }
    catch (const std::exception& ex)
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::cout << "Error: " << ex.what() << std::endl;
    }
}
void MyClientBase::print(const std::vector<MyClient>& clientList)
{
    for (auto row : clientList)
    {
        std::cout << "name = " << row.name << "; surname = " << row.surname << "; email = " << row.email << "; phone = " << row.phone << std::endl;
    }
}