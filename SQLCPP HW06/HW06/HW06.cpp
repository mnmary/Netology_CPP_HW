// HW06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <windows.h>

class User {
public:
    std::string name = "";
    std::string phone = "";
    int karma = 0;
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::field(a, phone, "phone");
        Wt::Dbo::field(a, karma, "karma");
    }
};

int main()
{
    try
    {
        std::string connectionString =
            "host=localhost"
            " port=5432"
            " dbname=test"
            " user=postgres"
            " password=11223344";
        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));
        session.mapClass<User>("user");
        //session.createTables();
        
        Wt::Dbo::Transaction transaction{ session };

        std::unique_ptr<User> user{ new User() };
        user->name = "Joe11";
        user->phone = "1234567890";
        user->karma = 13;
        Wt::Dbo::ptr<User> userPtr = session.add(std::move(user));
        transaction.commit();

        Wt::Dbo::Transaction transaction2{ session };
        Wt::Dbo::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe11");
        std::cout << "Joe has karma: " << joe->karma << std::endl;
        joe.modify()->name = "John";
        joe.modify()->karma = 100;
        transaction2.commit();


        typedef Wt::Dbo::collection<Wt::Dbo::ptr<User>> Users;
        Wt::Dbo::Transaction transaction1{ session };
        Users users = session.find<User>();
        std::cout << "We have " << users.size() << " users:" << std::endl;
        for (const Wt::Dbo::ptr<User>& user : users)
        {
            std::cout << " user " << user->name
                << " with karma of " << user->karma << std::endl;
        }
        transaction1.commit();
    }
    catch (const Wt::Dbo::Exception& e) 
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);

        std::cout << e.what() << std::endl;
    }

    std::cout << "Hello World!\n";

}


