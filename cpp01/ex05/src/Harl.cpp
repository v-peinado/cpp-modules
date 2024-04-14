/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:16:44 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 22:12:55 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "🤖  I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do! 🤖" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "⏺️  I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! ⏺️" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "⚠️  I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month. ⚠️" << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "❌  This is unacceptable! I want to speak to the manager now. ❌" << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level) {
    // vamos a hacer un array de punteros a funciones tipo void
    // que apuntan a las funciones de la clase Harl (Harl::*Levels[])
    // seguido de () para indicar que es un array de punteros a funciones que no reciben argumentos    
	void (Harl::*Levels[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
        };
    switch (level[0]) {
        case 'D':
            (this->*Levels[0])();
            break;
        case 'I':
            (this->*Levels[1])();
            break;
        case 'W':
            (this->*Levels[2])();
            break;
        case 'E':
            (this->*Levels[3])();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
}