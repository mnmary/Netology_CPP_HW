#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include <windows.h>
#include <vector>

struct MyClient
{
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
};

class MyClientBase
{
private:
    std::string _connectionString;
public:
    MyClientBase(const std::string& connectionString);
    void MyClientBase::createTable();
    void createClient(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone);
    void addPhone(const std::string& name, const std::string& phone);
    void updateClients(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail);
    void deletePhone(const std::string& email, const std::string& phone);
    void deleteClient(const std::string& email);
    std::vector<MyClient> findClients(const std::string& searchString);
    void print(const std::vector<MyClient>& clientList);
};