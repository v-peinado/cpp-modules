/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:04:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/10 13:48:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* CONSTRUCTORS */

Brain::Brain() {
    std::cout << "Brain has been created." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain has been destroyed." << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &rhs) {
    std::cout << "Brain assignation operator called." << std::endl;
    //std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = rhs._ideas[i];
        }
    }
    return *this;
}

/* MEMBER FUNCTIONS */

void Brain::setIdea(int index, std::string idea) {
    if(index < 0 || index >= 100)
        return;
    this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if(index < 0 || index >= 100)
        return "Invalid index.";
    return this->_ideas[index];
}

void Brain::printIdeas() const {
    for (int i = 0; i < 100; i++) {
        std::cout << "Idea " << i << ": " << this->_ideas[i] << std::endl;
    }
}