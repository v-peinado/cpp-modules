/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:25:48 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:26:07 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* CONSTRUCTORS */

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal has been created." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal has been destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
    std::cout << "WrongAnimal assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound." << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}