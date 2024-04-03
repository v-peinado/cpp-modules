/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:07 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/03 23:02:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "***********************" << std::endl;
    std::cout << "*  PHONEBOOK CREATED  *" << std::endl;
    std::cout << "***********************" << std::endl;
    this->_maxIndex = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "bye bye" << std::endl;
}

void PhoneBook::addContact()
{
    if (this->_maxIndex <= 7)
    {   
        this->_contacts[this->_maxIndex].setValues("name");
        this->_contacts[this->_maxIndex].setValues("lastName");
        this->_contacts[this->_maxIndex].setValues("nickname");
        this->_contacts[this->_maxIndex].setValues("phoneNumber");
        this->_contacts[this->_maxIndex].setValues("darkestSecret");
        this->_contacts[this->_maxIndex]._contactIndex = this->_maxIndex;
        this->_contacts[this->_maxIndex]._arrayIndex = this->_maxIndex;
        std::cout << "Contact added, Index: " <<  _maxIndex << std::endl;
        this->_maxIndex++;
    }
    else
    {
        std::cout << "The PhoneBook is full. Do you want to overwrite the oldest contact?(y/n)" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "y" || answer == "Y")
        {
            int oldest = oldestContact(this->_contacts);
            this->_contacts[oldest].setValues("name");
            this->_contacts[oldest].setValues("lastName");
            this->_contacts[oldest].setValues("nickname");
            this->_contacts[oldest].setValues("phoneNumber");
            this->_contacts[oldest].setValues("darkestSecret");
            this->_contacts[oldest]._contactIndex = this->_maxIndex;
            this->_contacts[oldest]._arrayIndex = oldest;
            this->_maxIndex++;
            std::cout << "Contact added, Index: " <<  oldest << std::endl;
        }
        else
            std::cout << "The contact was not added" << std::endl;
    }
}

int PhoneBook::oldestContact(Contact contacts[])
{
    //Esta funcion debe retornar el indice del contacto mas antiguo
    //Es decir, el contacto cuyo _indexContact sea el menor
    // si el _indexContact menor esta en la posicion 3 del array retornara 3
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
    
    if(this->_maxIndex == 0)
    {
        std::cout << "The PhoneBook is empty" << std::endl;
        return;
    }
    std::cout << "Index?" << std::endl;
    std::cin >> index;
    if(index < 0 || index > 7)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if(index >= this->_maxIndex)
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

