/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:15:49 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 13:19:42 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* CONSTRUCTORS */

Cat::Cat() : Animal() {
    std::cout << "Cat has been created." << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat has been destroyed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor called." << std::endl;
    this->_brain = new Brain();
    *this = other;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat assignation operator called." << std::endl;
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

void Cat::makeSound() const {
    std::cout << "Meow meow." << std::endl;
}

Brain *Cat::getBrain() {
    return this->_brain;
}