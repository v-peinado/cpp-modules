/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:16:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 13:19:29 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog() : Animal() {
    std::cout << "Dog has been created." << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog has been destroyed." << std::endl;   
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy constructor called." << std::endl;
    this->_brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(const Dog &rhs) {
    std::cout << "Dog assignation operator called." << std::endl;
    if (this != &rhs) {
        _type = rhs._type; // Copiar el valor de _type
        // Eliminar el _brain actual si existe
        if (_brain) {
            delete _brain;
            _brain = NULL; // Importante: establecer a nullptr después de eliminar, porque el puntero sigue apuntando a la dirección de memoria anterior
        }
        // Copiar el _brain de rhs si existe
        if (rhs._brain) {
            _brain = new Brain(*(rhs._brain));
        }
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void Dog::makeSound() const {
    std::cout << "Woof woof." << std::endl;
}

Brain *Dog::getBrain() {
    return this->_brain;
}