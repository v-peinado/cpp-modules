/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:15:49 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:19:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* CONSTRUCTORS */

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat has been created." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat has been destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(){
    std::cout << "Cat copy constructor called." << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void Cat::makeSound() const {
    std::cout << "Meow meow." << std::endl;
}