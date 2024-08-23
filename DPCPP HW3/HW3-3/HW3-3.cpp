// HW3-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
enum Type
{
    tWarning,
    tError,
    tFatalError,
    tUnknown
};

class LogMessage 
{
private:
    Type logType{Type::tUnknown};
    std::string logMessage{""};
public:
    LogMessage(const Type type, const std::string& message) : logType{ type }, logMessage{ message }
    {
    };
    Type type() const
    {
        return this->logType;
    };
    const std::string& message() const
    {
        return this->logMessage;
    };
};

class MHandler
{
protected:
    //передавать сообщение следующему обработчику
    MHandler* nextHandler;
public:
    MHandler(MHandler* next = nullptr) : nextHandler {next}
    {
    };
    virtual ~MHandler() = default;
    virtual void checkMessage(const LogMessage& message) 
    {
    };
};

class ErrorHandler : public MHandler
{
private:
    std::ofstream errorLog;
public:
    ErrorHandler(MHandler* next, const std::string& fileName) : MHandler(next)
    {
        errorLog.open(fileName);
        if (!(errorLog.is_open())) 
        {
            std::cout << "No log file " << fileName << " found" << std::endl;
        }

    };

    ~ErrorHandler()
    {
        errorLog.close();
    };
    //обрабатывать сообщение только определённого типа
    //передавать сообщение следующему обработчику
    void checkMessage(const LogMessage& message) override
    {
        if (message.type() == Type::tError)
        {
            //это свой тип сообщения - обработаем
            errorLog << message.message() << std::endl;
        }
        else
        {
            if (nextHandler != nullptr)
            {
                //передаем следующему
                nextHandler->checkMessage(message);//полиморфизм!
            }
        }
    }
};

class WarningHandler : public MHandler
{
public:
    WarningHandler(MHandler* next) : MHandler(next)
    {
    };
    //обрабатывать сообщение только определённого типа
    //передавать сообщение следующему обработчику
    void checkMessage(const LogMessage& message) override
    {
        if (message.type() == Type::tWarning)
        {
            //это свой тип сообщения - обработаем
            std::cout << message.message() << std::endl;
        }
        else
        {
            if (nextHandler != nullptr)
            {
                //передаем следующему
                nextHandler->checkMessage(message);//полиморфизм!
            }
        }
    }
};

class FatalErrorHandler : public MHandler
{
public:
    FatalErrorHandler(MHandler* next) : MHandler(next) 
    {
    };
    //обрабатывать сообщение только определённого типа
    //передавать сообщение следующему обработчику
    void checkMessage(const LogMessage& message) override
    {
        if (message.type() == Type::tFatalError)
        {
            //это свой тип сообщения - обработаем
            std::cout << "Fatal error!" << std::endl;
            throw(message.message());
        }
        else
        {
            if (nextHandler != nullptr)
            {
                //передаем следующему
                nextHandler->checkMessage(message);//полиморфизм!
            }
        }
    }
};

class UnknownHandler : public MHandler
{
public:
    UnknownHandler(MHandler* next) : MHandler(next)
    {
    };
    //обрабатывать сообщение только определённого типа
    //передавать сообщение следующему обработчику
    void checkMessage(const LogMessage& message) override
    {
        if (message.type() == Type::tUnknown)
        {
            //это свой тип сообщения - обработаем
            std::cout << "Unknown message!" << std::endl;
            throw(message.message());
        }
        else
        {
            if (nextHandler != nullptr)
            {
                //передаем следующему
                nextHandler->checkMessage(message);//полиморфизм!
            }
        }
    }
};

int main()
{
    LogMessage message(Type::tWarning, "WARNING MESSAGE");

    UnknownHandler    unknown(nullptr);
    WarningHandler    warning(&unknown);
    ErrorHandler      error(&warning, "errorLog.txt");
    FatalErrorHandler fatalError(&error);
    fatalError.checkMessage(message);

    return 0;
}

