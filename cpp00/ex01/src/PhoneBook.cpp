/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:07 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/04 17:39:03 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "***********************" << std::endl;
    std::cout << "*  PHONEBOOK \U0001F4DE \U0001F4DE \U0001F4DE *" << std::endl;
    std::cout << "***********************" << std::endl;
    this->_maxIndex = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Bye bye \U0001F44B\n" << std::endl;
}

void PhoneBook::addContact()
{
    int index;
    if (this->_maxIndex <= 7)
        index = this->_maxIndex;
    else
    {
        std::cout << "The PhoneBook is full. The oldest contact will be overwritten." << std::endl;
        index = oldestContact(this->_contacts);
    }
    this->_contacts[index].setValues("name");
    this->_contacts[index].setValues("lastName");
    this->_contacts[index].setValues("nickname");
    this->_contacts[index].setValues("phoneNumber");
    this->_contacts[index].setValues("darkestSecret");
    this->_contacts[index]._contactIndex = this->_maxIndex;
    this->_contacts[index]._arrayIndex = index;
    std::cout << "Contact added, Index: " << index << std::endl;
    this->_maxIndex++;
}

int PhoneBook::oldestContact(Contact contacts[])
{
    int oldest = 0;
    for (int i = 0; i <= 7; i++)
    {
        if (contacts[i]._contactIndex < contacts[oldest]._contactIndex)
            oldest = i;
    }
    return (oldest);
}

void PhoneBook::searchContact()
{
    int index;

    if (this->_maxIndex == 0)
    {
        std::cout << "The PhoneBook is empty" << std::endl;
        return;
    }
    std::cout << "Index?" << std::endl;
    std::cin >> index;
    if (index < 0 || index > 7)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (index >= this->_maxIndex)
    {
        std::cout << "Contact not found" << std::endl;
        return;
    }
    for (int i = 0; i <= 7; i++)
    {
        if (index == i)
        {
            this->_contacts[i].getValues();
            return;
        }
    }
}
