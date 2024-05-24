/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/24 17:58:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    std::cout << "**CONTRUCTORS**" << std::endl;
    //ScavTrap *a = new ScavTrap("Player1");
    std::cout << std::endl;
    std::cout << "** Player 1**" << std::endl;
    ClapTrap *a = new ScavTrap("Player1"); // Es valido porque ScavTrap hereda de ClapTrap

    std::cout << std::endl;
    std::cout << "** Player 2**" << std::endl;
    ScavTrap *b = new ScavTrap("Player2");
    
    std::cout << std::endl;
    std::cout << "**GET VALUES**" << std::endl;
    b->getValues();
    std::cout << std::endl; 
    
    std::cout << "**ATTACK**" << std::endl;
    a->attack("Player2");
    b->takeDamage(a->getAttackDamage());
    b->beRepaired(5);
    b->attack("Player1");
    b->guardGate();
    //a->setAttackDamage(5);
    a->attack("Player2");
    b->takeDamage(a->getAttackDamage());
    b->beRepaired(10);
    std::cout << std::endl;
    std::cout << "**DESTRUCTORS**" << std::endl;
    std::cout << std::endl;
    std::cout << "** Player 1**" << std::endl;
    delete a;
    std::cout << "** Player 2**" << std::endl;
    delete b;
    return 0;
}