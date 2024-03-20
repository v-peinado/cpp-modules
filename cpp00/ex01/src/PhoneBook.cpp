#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Constructor empty" << std::endl;
}

PhoneBook::PhoneBook(std::string name, std::string age) : _name(name), _age(age)
{
    std::cout << "Constructor with name: " << name << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "byebye" << std::endl;
}

std::string PhoneBook::getName()
{
    return _name;
}

void PhoneBook::setName(std::string name)
{
    _name = name;
}
