#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class PhoneBook
{
    private:
        std::string _name;
        std::string _age;
        void setName(std::string name);

    public:
        
        std::string getName();
        PhoneBook();
        PhoneBook(std::string name, std::string age);
        ~PhoneBook();
};

#endif
