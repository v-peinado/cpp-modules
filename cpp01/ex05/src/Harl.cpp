/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:16:44 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 22:38:37 by vpeinado         ###   ########.fr       */
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
	void (Harl::*levels[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
        };
        
    int i = 0;
    // vamos a hacer un array de strings con los niveles de log para comparar y segun el indice ejecutar la funcion correspondiente
	std::string lvls[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for(i = 0; i < 4; i++)
		if(level == lvls[i])
			break;
    
    switch (i) {
        case 0:
            (this->*levels[0])();
            break;
        case 1:
            (this->*levels[1])();
            break;
        case 2:
            (this->*levels[2])();
            break;
        case 3:
            (this->*levels[3])();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
}