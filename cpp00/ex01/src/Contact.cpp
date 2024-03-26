/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/26 21:19:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void Contact::setValues(std::string value)
{
    if((value.compare("") == 0))
    {
        std::cout << "Desbes escribir " << value << std::endl;
    }
    else
    {
        std::cout << "Enter the " << value << std::endl;
        std::getline(std::cin, value);
    }
}
