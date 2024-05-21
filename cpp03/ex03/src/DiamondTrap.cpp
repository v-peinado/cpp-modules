/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:35:29 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/20 21:26:54 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* CONSTRUCTORS */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    this->_attackDamage = FragTrap::getValue("attack damage");
    this->_hitpoints = FragTrap::getValue("hitpoints");
    this->_energyPoints = ScavTrap::getValue("energy points");
    
    std::cout << "DiamondTrap " << _name << " is here!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap assignation operator called." << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitpoints = rhs._hitpoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void DiamondTrap::getValues()
{
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Hitpoints: " <<  this->_hitpoints << std::endl;
    std::cout << "Energy Points: " << this->_energyPoints << std::endl;
    std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}