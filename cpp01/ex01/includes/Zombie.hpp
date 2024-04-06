/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:01:26 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/06 13:30:37 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        
        void setName(std::string name);
        void announce();
};

Zombie* zombieHorde( int N, std::string name);


#endif