/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:06:36 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/20 21:43:54 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HHP
#define FRAGTRAP_HHP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        int _fragHitpoints;
        int _fragEnergyPoints;
        int _fragAttackDamage;
    public:
        FragTrap(std::string name);
        virtual ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &rhs);

        int getValue(std::string value);

        void highFivesGuys(void);
};

#endif