/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:27:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/07 15:30:47 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* CONSTRUCTORS */

WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat has been created." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat has been destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(){
    std::cout << "WrongCat copy constructor called." << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
    std::cout << "WrongCat assignation operator called." << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void WrongCat::makeSound() const {
    std::cout << "... (Looks at you disapprovingly)" << std::endl;
}