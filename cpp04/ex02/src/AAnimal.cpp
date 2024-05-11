/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:02:49 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 14:24:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* CONSTRUCTORS */

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "AAnimal has been created." << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal has been destroyed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    std::cout << "AAnimal copy constructor called." << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
    std::cout << "AAnimal assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */


const std::string& AAnimal::getType() const {
    return this->_type;
}
