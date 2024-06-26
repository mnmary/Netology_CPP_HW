// HW06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <windows.h>
class Book;

class Publisher {
public:
    std::string name = "";
    Wt::Dbo::collection< Wt::Dbo::ptr<Book> > books;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Stock;
class Shop {
public:
    std::string name = "";
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stocks;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};


class Book {
public:
    std::string title = "";
    Wt::Dbo::ptr<Publisher> publisher_id;
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stocks;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher_id, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Sale;


class Stock {
public:
    int count = 0;
    Wt::Dbo::ptr<Book> book_id;
    Wt::Dbo::ptr<Shop> shop_id;
    Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sales;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book_id, "book");
        Wt::Dbo::belongsTo(a, shop_id, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    double price = 0.0;
    std::string date_sale = "2000-01-01";
    int count = 0;
    Wt::Dbo::ptr<Stock> stock_id;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock_id, "stock");
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

        Wt::Dbo::Transaction transaction{ session };

        session.mapClass<Publisher>("publisher");
        session.mapClass<Shop>("shop");
       session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");
        session.dropTables();
        session.createTables();
        
        transaction.commit();
    }
    catch (const Wt::Dbo::Exception& e) 
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);

        std::cout << e.what() << std::endl;
    }

    std::cout << "Hello World!\n";

}


