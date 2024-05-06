/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:06:36 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/06 18:36:57 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HHP
#define FRAGTRAP_HHP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        
    public:
        FragTrap(std::string name);
        virtual ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &rhs);

        void highFivesGuys(void);
};

#endif