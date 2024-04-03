/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/03 23:19:31 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <string>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setValues(std::string value)
{
    std::string input;
    std::cout << "Enter the " << value << ": " << std::endl;
    if (!std::getline(std::cin, input)) {
        std::cerr << "Error de lectura o EOF detectado" << std::endl;
    }
    else if (input.empty())
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
