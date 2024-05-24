/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:18:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/24 17:27:31 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HHP
#define SCAVTRAP_HHP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        bool _isGuardGate;
        int _scavHitpoints;
        int _scavEnergyPoints;
        int _scavAttackDamage;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        virtual ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &rhs);
        
        int getValue(std::string value);
        void attack(std::string const &target);
        void guardGate();
};

#endif