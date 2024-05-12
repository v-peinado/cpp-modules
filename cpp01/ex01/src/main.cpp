/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:12:17 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/07 15:45:00 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int main(void) {
    std::string name = "Zombie";
    Zombie *walkers = zombieHorde(N, name);
    
    delete [] walkers;
    return 0;
}