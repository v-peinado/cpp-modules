/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:07 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/26 01:01:51 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*****************
** Constructors **
*****************/

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitpoints = rhs._hitpoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

/*********************
** Member functions **
*********************/

void ClapTrap::attack(std::string const &target)
{
    if(_hitpoints < 1)
    {
        std::cout << "ClapTrap " << _name << " is dead and cant attack" << std::endl;
        return;
    }
    if(_energyPoints < 1)
    {
        std::cout << "ClapTrap " << _name << " has no energy and cant attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " have " << _energyPoints << " energy points"<< std::endl;
}

void ClapTrap::takeDamage(int amount)
{
    if(_hitpoints < 1)
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
        return;
    }
    if(amount < 1)
    {
        std::cout << "ClapTrap " << _name << " takes no damage" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    _hitpoints -= amount;
    if(_hitpoints < 1)
    {
        std::cout << "ClapTrap " << _name << " has died" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " has " << _hitpoints << " hitpoints" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitpoints < 1)
    {
        std::cout << "ClapTrap " << _name << " is dead and cant be repaired" << std::endl;
        return;
    }
    if(_energyPoints < 1)
    {
        std::cout << "ClapTrap " << _name << " has no energy and cant be repaired" << std::endl;
        return;
    }
    if(amount < 1)
    {
        std::cout << "ClapTrap " << _name << " takes no healing" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " points of health!" << std::endl;
    _hitpoints += amount;
}
/**********************
 * No subject functions
 * *******************/

void ClapTrap::setAttackDamage(int damage)
{
    std::cout << "ClapTrap " << _name << " has set attack damage to " << damage << std::endl;
    _attackDamage = damage;
}

int ClapTrap::getAttackDamage()
{
    return _attackDamage;
}
