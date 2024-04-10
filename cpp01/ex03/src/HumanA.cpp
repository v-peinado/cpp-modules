/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:37:26 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/10 19:47:15 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name) , _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(void) {
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}