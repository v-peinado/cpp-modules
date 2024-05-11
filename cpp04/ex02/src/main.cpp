/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:16 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 14:36:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
   -Clases abstractas: Es una clase que contiene al menos un método virtual puro. No se pueden instanciar objetos de una clase abstracta.
    En C++, una clase se considera abstracta si contiene al menos un método virtual puro. 
    La presencia de un método virtual puro en una clase indica que la clase no proporciona una implementación completa de todos sus métodos y,
    por lo tanto, no puede ser instanciada directamente. 
    En cambio, se utiliza como una interfaz base para otras clases derivadas que proporcionan implementaciones concretas de los métodos virtuales puros.
    En este caso, la clase AAnimal es una clase abstracta que contiene un método virtual puro makeSound(), 
    el compilador no permite instanciar objetos de esta clase, a no ser que se use AAanimal *animal = new Dog();
    En este caso, se puede instanciar un objeto de la clase derivada Dog, que hereda de AAnimal.
    La intención de una clase abstracta es proporcionar una interfaz común 
    y definir un conjunto de comportamientos que deben ser implementados por las clases derivadas.
*/

int main() {

    std::cout << "-------------------" << std::endl;
    std::cout << "---- Make animal---" << std::endl;
    std::cout << "-------------------" << std::endl;
    //Al ser una clase abstracta no se puede instanciar
    //AAnimal *animal = new AAnimal();

    std::cout << "-------------------" << std::endl;
    std::cout << "---- Make dog------" << std::endl;
    std::cout << "-------------------" << std::endl;
    Dog *dog = new Dog();
    AAnimal *animal = new Dog();

    std::cout << "-------------------" << std::endl;
    std::cout << "---- SOUNDS--------" << std::endl;
    std::cout << "-------------------" << std::endl;
    
    dog->makeSound();
    animal->makeSound();

    std::cout << "-------------------" << std::endl;
    std::cout << "---- Make wrong----" << std::endl;
    std::cout << "-------------------" << std::endl;

    WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << "-------------------" << std::endl;
    std::cout << "---- DELETE--------" << std::endl;
    std::cout << "-------------------" << std::endl;
    
    delete animal;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
}