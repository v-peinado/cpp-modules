/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:19:56 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 21:36:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl Harl;
    std::string prompt;
    while(!(prompt.compare("EXIT") == 0 || std::cin.eof()))
    {
        std::cout << ">";
        std::getline(std::cin, prompt);
        Harl.complain(prompt);
    }
    return (0);
}