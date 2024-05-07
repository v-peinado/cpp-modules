/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:02:49 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:22:49 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* CONSTRUCTORS */

Animal::Animal() : _type("Animal") {
    std::cout << "Animal has been created." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal has been destroyed." << std::endl;
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called." << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &rhs) {
    std::cout << "Animal assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void Animal::makeSound() const {
    std::cout << "Animal sound." << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}
