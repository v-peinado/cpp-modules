#include <iostream>
#include "PhoneBook.hpp"

int main (void)
{
    // std::string prompt;
    // std::cout << "PHONEBOOK, ni puta idea de clases" << std::endl;
    // while(1)
    // {
    //     std::cout << "$>";
    //     std::getline(std::cin, prompt);
    //     if (prompt == "exit" || std::cin.eof())
    //         break;
    //     else if(prompt == "ADD")
    //         std::cout << "Funcion añadir" << std::endl;
    //     else if(prompt == "SEARCH")
    //         std::cout << "Funcion buscar" << std::endl;
    // }
    // return (0);

    //Constructor normal

    //Constructor con argumentos
    PhoneBook *s = new PhoneBook();

    PhoneBook a("Antonio");
    std::cout << a.getName() << std::endl;


    delete s;
}
