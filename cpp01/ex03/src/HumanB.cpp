/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:06:59 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/10 20:44:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack (void) {
    if(this->_weapon->getType() != "")
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
        this->_weapon = &weapon;
}
