/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:16 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:17:54 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    j->makeSound(); // Will output the cat sound!
    i->makeSound();
    delete j;
    delete i;
    return 0;
}