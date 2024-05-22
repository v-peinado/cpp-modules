/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:18 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/22 20:55:22 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}
/*
    El constructor de int y float se encargan de convertir el valor a punto fijo
*/
Fixed::Fixed(const int value) { //Recibiremos un valor entero
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = value << _fractionalBits; 
    /*
        Convertiremos el valor entero a punto fijo, desplazar el valor entero a la izquierda 8 bits,
        ejemplo:
        n = 2
        n << 8 = 512 decimal
        2 = 00000010
        00000010 << 8 = 0000001000000000 = 512
    */
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(value * (1 << _fractionalBits));
    /*
        Convertiremos el valor flotante a punto fijo, multiplicar el valor flotante por 2^8 y redondear el valor
        ejemplo:
        n = 2.5
        n * 2^8 = 640
        2.5 = 10.1
        10.1 * 2^8 = 640
    */
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
        this->_fixedPoint = copy.getRawBits();
    return *this;
}


/*
    Sobrecarga del operador de inserción
    Se imprime el valor del punto fijo convertido a flotante
    de esta forma se puede imprimir el valor de un objeto Fixed
    cuando usamos std::cout << fixed << std::endl;
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPoint = raw;
}

/*
    Convertir el valor en punto fijo a flotante o int
    Se realizan las operaciones inversas a las realizadas en los constructores
*/

float Fixed::toFloat(void) const {
    return (float)this->_fixedPoint / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPoint >> _fractionalBits;
}