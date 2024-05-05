/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/05 12:23:56 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    //ClapTrap a("Player1");
    //ClapTrap b("Player2");
    std::cout << "**CONTRUCTORS**" << std::endl;
    ClapTrap *a = new ClapTrap("Player1");
    ClapTrap *b = new ClapTrap("Player2");
    std::cout << std::endl; 
    
    std::cout << "**ATTACK**" << std::endl;
    a->attack("Player2");
    b->takeDamage(a->getAttackDamage());
    b->beRepaired(5);
    a->setAttackDamage(5);
    a->attack("Player2");
    b->takeDamage(a->getAttackDamage());
    b->beRepaired(10);
    std::cout << std::endl;
    std::cout << "**DESTRUCTORS**" << std::endl;
    delete a;
    delete b;
    return 0;
}