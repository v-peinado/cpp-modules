/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/31 20:10:56 by vpeinado         ###   ########.fr       */
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
            std::cout << "Desbes escribir " << value;
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

