/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:16:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:19:48 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog has been created." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog has been destroyed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(){
    std::cout << "Dog copy constructor called." << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void Dog::makeSound() const {
    std::cout << "Woof woof." << std::endl;
}