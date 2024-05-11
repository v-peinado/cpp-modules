/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:16:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 14:19:10 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* CONSTRUCTORS */

Dog::Dog() : AAnimal() {
    std::cout << "Dog has been created." << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog has been destroyed." << std::endl;   
}

Dog::Dog(const Dog &other) : AAnimal(other){
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
            /*
            Importante: establecer a nullptr(o NULL en c++98) después de eliminar, 
            porque el puntero sigue apuntando a la dirección de memoria anterior y puede causar problemas
            Diferencias entre NULL y nullptr: 
            NULL es una macro que se define como 0 y nullptr(c++11) es explicitamente un puntero nulo.
            NULL se puede usar en diferentes contextos, pero nullptr es más seguro y se recomienda usarlo en c++11 en lugar de NULL
             */
            _brain = NULL; 
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