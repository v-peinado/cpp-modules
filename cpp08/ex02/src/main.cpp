/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:36 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/26 13:25:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stdint.h>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(42);

    //test que no se puede aplicar cambios a un contenedor constante
    MutantStack<int>::iterator it = mstack.begin();
    (*it) = 42; //cambiamos el valor 5 por 42
    
    std::cout << "value: " << *it << std::endl;

    std::cout << "==============================" << std::endl
              << "Testing with MutantStack<int>:" << std::endl
              << "==============================" << std::endl;
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);

    std::cout << "MutantStack reverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Pop" << std::endl;
    mstack.pop();
    std::cout << "Our implement Top: " << mstack.top() << std::endl;
    std::cout << "Bottom: " << mstack.bottom() << std::endl;

    std::cout << "MutantStack after pop: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);

    std::cout << "Print address of stack elements: " << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << &(*it) << " ";
    std::endl(std::cout);
    /*
        para que veamos que son contiguas las direcciones de memoria
        convertirlo a un tipo de entero lo suficientemente grande como para contener una dirección de memoria, como uintptr_t
        veremos que las direcciones de memoria son contiguas separdas por 4 bytes = 32 bits, tamaño de un int en este sistema
        veremos que la pila crece hacia abajo es decir que las direcciones de memoria son menores a medida que se añaden elementos
        +----------------------+ 0xFFFFFFFF (dirección de memoria más alta)
        |                      |
        |       Heap           | <--- Crece hacia arriba
        |                      |
        +----------------------+
        |                      |
        |      Libre           |
        |                      |
        +----------------------+
        |                      |
        |       Stack          | <--- Crece hacia abajo
        |                      |
        +----------------------+
        |   Datos Estáticos    |
        +----------------------+
        |    Código (Text)     |
        +----------------------+ 0x00000000 (dirección de memoria más baja)
    */
    std::cout << "Print address of stack elements after cast to uintptr_t: " << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << reinterpret_cast<uintptr_t>(&(*it)) << " ";
    std::endl(std::cout);
    std::cout << "==============================" << std::endl
              << "       Testing with list:" << std::endl
              << "==============================" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    mlist.push_back(42);

    std::cout << "List: ";
    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);

    std::cout << "List reverse: ";
    for (std::list<int>::reverse_iterator it = mlist.rbegin(); it != mlist.rend(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);
    
    std::cout << "Front: " << mlist.front() << std::endl;
    std::cout << "Back: " << mlist.back() << std::endl;
    std::cout << "Size: " << mlist.size() << std::endl;
    std::cout << "Pop" << std::endl;
    mlist.pop_back();
    std::cout << "Back after pop: " << mlist.back() << std::endl;
    std::cout << "Print address of list elements: " << std::endl;
    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
        std::cout << &(*it) << " ";
    std::endl(std::cout);
    //Al imprimir las direcciones de memoria de las listas nos damos cuenta de que no son contiguas
    std::cout << "Print address of list elements after cast to uintptr_t: " << std::endl;
    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
        std::cout << reinterpret_cast<uintptr_t>(&(*it)) << " ";
    std::endl(std::cout);
    
    std::cout << "==============================" << std::endl
              << "         Subject test:"         << std::endl
              << "==============================" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(5);
    mstack2.push(17);
    std::cout << "top: " << mstack2.top() << std::endl;
    mstack2.pop();
    std::cout << "size after pop: " << mstack2.size() << std::endl;
    mstack2.push(3);
    mstack2.push(5);
    mstack2.push(737);
    //[...]
    mstack2.push(0);
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
    std::cout << *it2 << std::endl;
    ++it2;
    }
    std::stack<int> s(mstack2);
    return 0;
}