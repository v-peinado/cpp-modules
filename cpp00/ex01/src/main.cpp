/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:55:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/03 21:33:50 by vpeinado         ###   ########.fr       */
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
    while(!(prompt.compare("EXIT") == 0 || std::cin.eof()))
    {
        std::cout << ">";
        std::getline(std::cin, prompt);
        if(prompt.compare("ADD") == 0)
            MyPhoneBook->addContact();
        else if(prompt.compare("SEARCH") == 0)
        {
            MyPhoneBook->searchContact();
        }
            
        else if(prompt.empty())
            continue;
        else
            std::cout << "**Invalid command" << std::endl;
    }
    delete MyPhoneBook;
    return (0);
}
