/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:18:41 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/06 13:20:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++) {
        horde[i].setName(name);
        horde[i].announce();
    }  
    return horde;
}