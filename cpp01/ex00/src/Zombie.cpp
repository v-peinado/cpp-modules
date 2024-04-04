/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:49:25 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/04 23:46:19 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << this->_name << " has died... again" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

