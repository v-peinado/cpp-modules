/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/02 22:31:59 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setValues(std::string value)
{
    std::string input;
    while(input.compare("") == 0)
    {
        std::cout << "Enter the " << value << ": ";
        std::getline(std::cin, input);
        if ((input.compare("") == 0))
        {
            std::cout << "You must enter " << value << std::endl;
            std::getline(std::cin, input);
        }
    }
    if (value.compare("name") == 0)
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

void Contact::getValues()
{
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Last Name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

