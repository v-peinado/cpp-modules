/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:18 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/18 21:56:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int value) {
    //std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    //std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(value * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &copy) {
   // std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
        this->_fixedPoint = copy.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed() {
   // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPoint / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPoint >> _fractionalBits;
}

Fixed Fixed::operator+(const Fixed &value) const {
    return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(const Fixed &value) const {
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value) const {
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value) const {
    return Fixed(this->toFloat() / value.toFloat());
}

Fixed &Fixed::operator++(void) {
    this->_fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->_fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator>(const Fixed &value) const {
    return this->toFloat() > value.toFloat();
}

bool Fixed::operator<(const Fixed &value) const {
    return this->toFloat() < value.toFloat();
}

bool Fixed::operator>=(const Fixed &value) const {
    return this->toFloat() >= value.toFloat();
}

bool Fixed::operator<=(const Fixed &value) const {
    return this->toFloat() <= value.toFloat();
}

bool Fixed::operator==(const Fixed &value) const {
    return this->toFloat() == value.toFloat();
}

bool Fixed::operator!=(const Fixed &value) const {
    return this->toFloat() != value.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

