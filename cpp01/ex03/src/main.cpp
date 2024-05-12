/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:12:25 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 16:56:20 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
    En este ejercicio se nos pide que creemos dos clases HumanA y HumanB que tengan un atributo Weapon. 
    Uno de los humanos puede tener arma o no.
    La diferencia es que uno de los humanos tiene un atributo Weapon que es una referencia, y el otro tiene un puntero.
    La diferencia entre un puntero y una referencia es que una referencia no puede ser nula, y un puntero sí.
    Por lo que a uno de los humanos hay que pasarle la referencia de la arma en el constructor, y al otro no hace falta
*/

int main() {
    {
        std::cout << "-------------------" << std::endl;
        std::cout << "---- Referencia ---" << std::endl;
        std::cout << "-------------------" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        std::cout << "-------------------" << std::endl;
        std::cout << "---- Puntero ------" << std::endl;
        std::cout << "-------------------" << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        std::cout << "-------------------" << std::endl;
        std::cout << "---- Puntero ------" << std::endl;
        std::cout << "--- Sin arma ------" << std::endl;
        std::cout << "-------------------" << std::endl;
        HumanB peter("Peter");
        peter.attack();
    }
return 0;
}