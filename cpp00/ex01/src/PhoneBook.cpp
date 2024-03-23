/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:07 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/23 00:58:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "PHONEBOOK" << std::endl;
    _index = 0;
    _nbrContacs = 0;
    for (int i = 0; i < 7; i++)
        this->_contacts[i] = new Contact();
}

PhoneBook::~PhoneBook()
{
    std::cout << "ALL CONTATCS DELETED" << std::endl;
    for (int i = 0; i < 7; i++)
        delete this->_contacts[i];
}

void PhoneBook::addContact()
{
    if (_index < 7)
    {
        _contacts[_index]->setValues("name");
        _index++;
        _nbrContacs++;
    }
    else
    {
        std::cout << "PhoneBook is full" << std::endl;
    }
}

