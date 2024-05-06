/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/06 19:35:26 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    std::cout << "**CONTRUCTORS**" << std::endl;
    //ScavTrap *a = new ScavTrap("Player1");
    //ClapTrap *a = new ScavTrap("Player1"); // Es valido porque ScavTrap hereda de ClapTrap
    DiamondTrap *b = new DiamondTrap("Player2");
    
    std::cout << std::endl; 
    
    std::cout << "**ATTACK**" << std::endl;
    //a->attack("Player2");
   // b->takeDamage(a->getAttackDamage());
    b->beRepaired(5);
    b->attack("Player1");
    //a->setAttackDamage(5);
    //a->attack("Player2");
    //b->takeDamage(a->getAttackDamage());
    b->beRepaired(10);
    b->whoAmI();
    
    
    std::cout << std::endl;
    std::cout << "**DESTRUCTORS**" << std::endl;
    //delete a;
    delete b;
    return 0;
}