/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:55:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/02 22:26:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main (void)
{
    PhoneBook *MyPhoneBook = new PhoneBook();
    std::string prompt;
    while(1)
    {
        std::cout << ">";
        std::getline(std::cin, prompt);
        if (prompt.compare("EXIT") == 0 || std::cin.eof())
            break;
        else if(prompt.compare("ADD") == 0)
            MyPhoneBook->addContact();
        else if(prompt.compare("SEARCH") == 0)
            MyPhoneBook->searchContact();
    }
    delete MyPhoneBook;

    return (0);
}
