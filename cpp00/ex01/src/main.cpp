/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:55:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/23 00:52:34 by vpeinado         ###   ########.fr       */
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
            std::cout << "Funcion añadir" << std::endl;
        else if(prompt.compare("SEARCH") == 0)
            std::cout << "Funcion buscar" << std::endl;
    }
    delete MyPhoneBook;

    return (0);
}
