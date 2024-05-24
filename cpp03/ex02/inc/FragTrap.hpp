/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:06:36 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/24 17:22:50 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HHP
#define FRAGTRAP_HHP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        
    public:
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &rhs);

        void highFivesGuys(void);
};

#endif