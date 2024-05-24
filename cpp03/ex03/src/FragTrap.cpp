/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:06:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/24 17:34:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTOR */

FragTrap::FragTrap() : ClapTrap() {
    this->_name = "FragTrap";
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_fragHitpoints = this->_hitpoints;
    this->_fragEnergyPoints = this->_energyPoints;
    this->_fragAttackDamage = this->_attackDamage;
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_fragHitpoints = this->_hitpoints;
    this->_fragEnergyPoints = this->_energyPoints;
    this->_fragAttackDamage = this->_attackDamage;
    std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

/* DESTRUCTOR */

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

/* COPY CONSTRUCTOR */

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
    *this = other;
}

/* ASSIGNATION OPERATOR */

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitpoints = rhs._hitpoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " is asking for a high five!" << std::endl;
}

int FragTrap::getValue(std::string value) {
    if (value == "hitpoints")
        return this->_hitpoints;
        //return this->_fragHitpoints;
    if (value == "energy points")
        return this->_energyPoints;
        //return this->_fragHitpoints;
    if (value == "attack damage")
        return this->_attackDamage;
        //return this->_fragAttackDamage;
    else
        return 0;
}
