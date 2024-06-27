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

void SearchShop(Wt::Dbo::Session& session, const std::string& searchString) 
{
    //1 ищем publisher id по наименованию
    Wt::Dbo::ptr<Publisher> PublisherId = session.find<Publisher>().where("name = ?").bind(searchString);

    //2 ищем список book id по publisher id
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> bookList = session.find<Book>().where("publisher_id = ?").bind(PublisherId);

    //3 ищем список stock id по списку book id
    std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Stock>>> stockList;
    for (const auto& id : bookList) 
    {
        stockList.push_back(session.find<Stock>().where("book_id = ?").bind(id.id()));
    }

    //4 ищем список shop id по списку stock id
    std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Shop>>> shopList;
    for (const auto& col : stockList) 
    {
        for (const auto& id : col) 
        {
            shopList.push_back(session.find<Shop>().where("id = ?").bind(id->shop_id));
        }
    }
    std::cout << std::endl << "Найдены магазины по строке поиска " << searchString << ": \n";
    std::set<std::string> names;
    for (const auto& col : shopList)
    {
        for (const auto& id : col) 
        {
            names.insert(id->name);
        }
    }
    int i = 1;
    for (const auto& name : names) 
    {
        std::cout << i << ". " << name << std::endl;
        i++;
    }
}



int main()
{
    setlocale(LC_ALL, "Rus");
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

        session.mapClass<Publisher>("publisher");
        session.mapClass<Shop>("shop");
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");
       // session.dropTables(); //не стоит использовать эту команду - она может выдать ошибку, если таблицы из списка нет в базе!!!
        session.createTables();
        
        Wt::Dbo::Transaction transaction{ session };
        std::unique_ptr<Publisher>publisher1{ new Publisher() };    //1 создаем объект - запись
        publisher1->name = "publisher1";    //данные объекта
        Wt::Dbo::ptr<Publisher> publisher1_ptr = session.add(std::move(publisher1));//добавляем в базу
        std::cout << "Добавили запись издательство: " << publisher1_ptr->name << std::endl;//функция возвращает добавленную запись в виде указателя объекта

        std::unique_ptr<Publisher>publisher2{ new Publisher() };
        publisher2->name = "publisher2";
        Wt::Dbo::ptr<Publisher> publisher2_ptr = session.add(std::move(publisher2));
        std::cout << "Добавили запись издательство: " << publisher2_ptr->name << std::endl;

        std::unique_ptr<Publisher>publisher3{ new Publisher() };
        publisher3->name = "publisher3";
        Wt::Dbo::ptr<Publisher> publisher3_ptr = session.add(std::move(publisher3));
        std::cout << "Добавили запись издательство: " << publisher3_ptr->name << std::endl;


        //
        std::unique_ptr <Book> Book1{ new Book() };
        Book1->title = "Pub 1 Book 1";
        Book1->publisher_id = publisher1_ptr;
        Wt::Dbo::ptr<Book> Book1_ptr = session.add(std::move(Book1));
        std::cout << "Добавили запись книга: " << Book1_ptr->title << std::endl;

        std::unique_ptr <Book> Book2{ new Book() };
        Book2->title = "Pub 2 Book 2";
        Book2->publisher_id = publisher2_ptr;
        Wt::Dbo::ptr<Book> Book2_ptr = session.add(std::move(Book2));
        std::cout << "Добавили запись книга: " << Book2_ptr->title << std::endl;

        std::unique_ptr <Book> Book3{ new Book() };
        Book3->title = "Pub 3 Book 3";
        Book3->publisher_id = publisher3_ptr;
        Wt::Dbo::ptr<Book> Book3_ptr = session.add(std::move(Book3));
        std::cout << "Добавили запись книга: " << Book3_ptr->title << std::endl;


        //
        std::unique_ptr<Shop> Shop1{ new Shop() };
        Shop1->name = "Shop1";
        Wt::Dbo::ptr<Shop> Shop1_ptr = session.add(std::move(Shop1));
        std::cout << "Добавили запись магазин: " << Shop1_ptr->name << std::endl;

        std::unique_ptr<Shop> Shop2{ new Shop() };
        Shop2->name = "Shop2";
        Wt::Dbo::ptr<Shop> Shop2_ptr = session.add(std::move(Shop2));
        std::cout << "Добавили запись магазин: " << Shop2_ptr->name << std::endl;

        std::unique_ptr<Shop> Shop3{ new Shop() };
        Shop3->name = "Shop3";
        Wt::Dbo::ptr<Shop> Shop3_ptr = session.add(std::move(Shop3));
        std::cout << "Добавили запись магазин: " << Shop3_ptr->name << std::endl;


        //
        std::unique_ptr<Stock> Stock1{ new Stock() };
        Stock1->book_id = Book1_ptr;
        Stock1->shop_id = Shop1_ptr;
        Stock1->count = 100;
        Wt::Dbo::ptr<Stock> Stock1_ptr = session.add(std::move(Stock1));
        std::cout << "Добавили запись стока: " << Stock1_ptr->count << std::endl;

        std::unique_ptr<Stock> Stock2{ new Stock() };
        Stock2->book_id = Book2_ptr;
        Stock2->shop_id = Shop2_ptr;
        Stock2->count = 120;
        Wt::Dbo::ptr<Stock> Stock2_ptr = session.add(std::move(Stock2));
        std::cout << "Добавили запись стока: " << Stock2_ptr->count << std::endl;

        //
        std::unique_ptr<Sale> sale_1{ new Sale() };
        sale_1->price = 100;
        sale_1->date_sale = "2024-06-26";
        sale_1->stock_id = Stock1_ptr;
        sale_1->count = 10;
        session.add(std::move(sale_1));

        std::unique_ptr<Sale> sale_2{ new Sale() };
        sale_2->price = 90;
        sale_2->date_sale = "2024-06-25";
        sale_2->stock_id = Stock2_ptr;
        sale_2->count = 20;
        session.add(std::move(sale_2));


        //
        std::string name;
        std::cout << "Введите название издательства для поиска: ";
        std::cin >> name;
        SearchShop(session, name);

        transaction.commit();      
    }
    catch (const Wt::Dbo::Exception& e) 
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);

        std::cout << e.what() << std::endl;
    }

}


