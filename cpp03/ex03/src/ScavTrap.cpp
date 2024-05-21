/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:53:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/21 03:58:56 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*****************
** Constructors **
*****************/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "ScavTrap " << this->_name << " has been created." << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_isGuardGate = false;
    this->_scavHitpoints = this->_hitpoints;
    this->_scavEnergyPoints = this->_energyPoints;
    this->_scavAttackDamage = this->_attackDamage;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "ScavTrap assignation operator called." << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitpoints = rhs._hitpoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
        this->_isGuardGate = rhs._isGuardGate;
    }
    return *this;
}

/*********************
 * Member functions **
 * *******************/
void ScavTrap::attack(std::string const &target)
{
    if( this->_hitpoints < 1)
    {
        std::cout << "ScavTrap " <<  this->_name << " is dead and cant attack" << std::endl;
        return;
    }
    if( this->_energyPoints < 1)
    {
        std::cout << "ScavTrap " <<  this->_name << " has no energy and cant attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " <<  this->_name << " attacks " << target << ", causing " <<  this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
    std::cout << "ScavTrap " <<  this->_name << " have " <<  this->_energyPoints << " energy points"<< std::endl;
}

void ScavTrap::guardGate()
{
    if(this->_isGuardGate)
    {
        std::cout << "ScavTrap " << this->_name << " have already activated the guard gate." << std::endl;
        return;
    }
    this->_isGuardGate = true;
    std::cout << "ScavTrap " << this->_name << " have activated the guard gate." << std::endl;
}

int ScavTrap::getValue(std::string value)
{
    if (value == "hitpoints")
        return this->_scavHitpoints;
    else if (value == "energy points")
        return this->_scavEnergyPoints;
    else if (value == "attack damage")
        return this->_scavAttackDamage;
    else
        return 0;
}