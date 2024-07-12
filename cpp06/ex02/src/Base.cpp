/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:24:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/12 14:00:13 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

/*******************
*     functions    *
*******************/

Base * generate() {
    std::srand(time(NULL));
    switch (rand() % 3)
    {
    case 0:
        std::cout << "New A" << std::endl;
        return new A;
    case 1:
        std::cout << "New B" << std::endl;
        return new B;
    case 2:
        std::cout << "New C" << std::endl;
        return new C;    
    default:
        std::cerr << "ERROR!!!!\n";
        return NULL;
        break;
    }
}

/*
    Si por ejemplo, p apunta a un puntero tipo A* y se intenta castear
    la conversion sera exitosa y dara como resultado diferente a NULL
    usando esto para poder identificar el tipo
*/
void identify(Base* p) {
    if(dynamic_cast<A*>(p))
    {
        std::cout << "A class" << std::endl;
        return ;
    }
    if(dynamic_cast<B*>(p))
    {
        std::cout << "B class" << std::endl;
        return ;
    }
    if(dynamic_cast<C*>(p))
    {
        std::cout << "C class" << std::endl;
        return ;
    }
    std::cerr << "Cant identify the class" << std::endl; 
}

/*
    Usaremos la misma logica que la funcion anterior, con la diferencia
    de que al usar una referencia no se puede devolver NULL, pero si se
    lanzara una excepcion que avisara que el casteo no ha sido valido.
    Podriamos intentar captar la excepcion std::bad_cast& e pero
    el subject no deja usar el encabezado typeinfo
*/
void identify(Base& r) {
	try {
		dynamic_cast<A&>(r);
		std::cout << "A class" << std::endl;
		return;
	} catch (...) {}

	try {
		dynamic_cast<B&>(r);
		std::cout << "B class" << std::endl;
		return;
	} catch (...) {}

	try {
		dynamic_cast<C&>(r);
		std::cout << "C class" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Can't identify the class" << std::endl;
}