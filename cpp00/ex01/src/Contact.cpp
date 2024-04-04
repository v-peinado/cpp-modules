/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/04 17:45:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::~Contact() {}


int Contact::only_spaces(std::string str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it != ' ') 
            return 0;
    }
    return 1;
}

void Contact::setValues(std::string value)
{
    std::string input;
    std::cout << "Enter the " << value << ": " << std::endl;
    if (!std::getline(std::cin, input)) {
        std::cout << "EOF detected. Bye bye \U0001F44B\n" << std::endl;
        exit(0);
    }
    else if (input.empty() || only_spaces(input))
    {
        std::cout << "**You must enter " << value << std::endl;
        setValues(value);
    } 
    else if (value.compare("name") == 0)
        this->_name = input;
    else if (value.compare("lastName") == 0)
        this->_lastName = input;
    else if (value.compare("nickname") == 0)
        this->_nickname = input;
    else if (value.compare("phoneNumber") == 0)
        this->_phoneNumber = input;
    else if (value.compare("darkestSecret") == 0)
        this->_darkestSecret = input;       
}
std::string truncate(std::string str)
{
  if (str.length() > 10) 
    return (str.substr(0, 9) + ".");
  return (str);
}


void Contact::getValues()
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nickname" ;
    std::cout << "|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|";
    std::cout << std::right << std::setw(10) << this->_arrayIndex;
    std::cout << "|";
    std::cout << std::right << std::setw(10) << truncate(this->_name);
    std::cout << "|";
    std::cout << std::right << std::setw(10) << truncate(this->_lastName);
    std::cout << "|";
    std::cout << std::right << std::setw(10) << truncate(this->_nickname);
    std::cout << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
