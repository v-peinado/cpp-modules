/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:18:40 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/05 14:59:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HHP
#define SCAVTRAP_HHP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool _isGuardGate;
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &rhs);

        void attack(std::string const &target);
        void guardGate();
};

#endif