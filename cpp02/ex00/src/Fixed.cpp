/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:05:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/13 12:48:03 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; //this se refiere al objeto actual, es un puntero que apunta a la dirección de memoria del objeto actual, copy es el objeto que se pasa como argumento
}

Fixed &Fixed::operator=(const Fixed &copy) { 
    std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
        this->_fixedPoint = copy.getFixed();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getFixed(void) const {
    std::cout << "getFixed member function called" << std::endl;
    return this->_fixedPoint;
}

void Fixed::setFixed(int const raw) {
    std::cout << "setFixed member function called" << std::endl;
    this->_fixedPoint = raw;
}