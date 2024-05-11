/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:16 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 13:21:57 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
    -Shallow copy: copia superficial, se copian los punteros, no los valores a los que apuntan. De esta forma, si se modifica un valor, se modifica en ambos objetos.
    -Deep copy: copia profunda, se copian los valores a los que apuntan los punteros. Se debe implementar un constructor de copia y un operador de asignación para realizar una 
        copia profunda. Lo que significa reservar memoria para el nuevo objeto y copiar los valores de los punteros.
        En este caso, se ha implementado un constructor de copia y un operador de asignación para la clase Dog. 
        Que copia el valor de _type y crea un nuevo objeto Brain con los valores de _brain.
*/

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "---- MAKE ANIMAL ARRAY ---" << std::endl;
    std::cout << "--------------------------" << std::endl;

    const int n = 10;
    Animal *animals[n];
    //Se hace un array de punteros a Animal
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    std::cout << "--------------------------" << std::endl;
    std::cout << "---- MAKE ANIMAL SOUNDS ---" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    for (int i = 0; i < n; i++) {
        animals[i]->makeSound();
    }

    std::cout << "--------------------------" << std::endl;
    std::cout << "---- COPY TEST------------" << std::endl;
    std::cout << "--------------------------" << std::endl;

    Dog *dog = new Dog();
    dog->getBrain()->setIdea(0, "I am a dog.");
    
    Dog *dog2 = new Dog(*dog);

    dog2->getBrain()->setIdea(0, "I am a dog too.");
    
    std::cout << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << dog2->getBrain()->getIdea(0) << std::endl;

    delete dog;
    delete dog2;

    std::cout << "--------------------------" << std::endl;
    std::cout << "---- ASSIGNATION TEST ----" << std::endl;
    std::cout << "--------------------------" << std::endl;

    Dog *dog3 = new Dog();
    dog3->getBrain()->setIdea(0, "I am a dog.");
    
    Dog *dog4 = new Dog();
    *dog4 = *dog3;

    dog4->getBrain()->setIdea(0, "I am a dog too.");
    
    std::cout << dog3->getBrain()->getIdea(0) << std::endl;
    std::cout << dog4->getBrain()->getIdea(0) << std::endl;

    delete dog3;
    delete dog4;
    
    
    std::cout << "--------------------------" << std::endl;
    std::cout << "---- DELETE ANIMALS ------" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    for (int i = 0; i < n; i++) {
        delete animals[i];
    }
}