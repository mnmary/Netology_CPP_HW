#include <iostream>
#include <pqxx/pqxx>
#include <windows.h>
#include <vector>

#include "MyClientBase.h"


int main()
{
		std::string connection_string = "host=127.0.0.1 port=5432 dbname=test user=postgres password=11223344";
        MyClientBase clients(connection_string);
        clients.createTable();
        clients.createClient("name1","surname1","email1","phone11");
        clients.createClient("name2", "surname2", "email2", "phone21");
        clients.createClient("name3", "surname3", "email3", "phone31");
        clients.createClient("name4", "surname4", "email4", "phone41");
        clients.addPhone("name1", "phone12");
        clients.addPhone("name1", "phone13");
        clients.addPhone("name1", "phone14");

        clients.addPhone("name2", "phone22");
        clients.addPhone("name2", "phone23");
        clients.addPhone("name2", "phone24");

        clients.addPhone("name3", "phone32");
        clients.addPhone("name3", "phone33");
        clients.addPhone("name3", "phone34");

        clients.addPhone("name4", "phone42");
        clients.addPhone("name4", "phone43");
        clients.addPhone("name4", "phone44");

        clients.updateClients("email1", "changename1", "changesurname1", "changeEmail1");
        clients.updateClients("email2", "changename2", "changesurname2", "changeEmail2");
        clients.updateClients("email3", "changename3", "changesurname3", "changeEmail3");
        clients.updateClients("email4", "changename4", "changesurname4", "changeEmail4");

        clients.deletePhone("changeEmail1", "phone14");
        clients.deletePhone("changeEmail2", "phone24");
        clients.deletePhone("changeEmail3", "phone34");
        clients.deletePhone("changeEmail4", "phone44");

        std::vector<MyClient> clientList = clients.findClients("changename1");
        clients.print(clientList);

        clientList = clients.findClients("changesurname2");
        clients.print(clientList);

        clientList = clients.findClients("changeEmail3");
        clients.print(clientList);

        clientList = clients.findClients("changename4");
        clients.print(clientList);

        clients.deleteClient("changeEmail1");
        clients.deleteClient("changeEmail2");
        clients.deleteClient("changeEmail3");
        clients.deleteClient("changeEmail4");
}