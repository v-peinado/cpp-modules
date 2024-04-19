/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/19 22:23:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("Player1");
    ClapTrap b("Player2");

    a.attack("Player2");
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(5);
    a.setAttackDamage(5);
    a.attack("Player2");
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(10);
    return 0;
}