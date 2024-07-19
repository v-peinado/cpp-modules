/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:00:26 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/19 15:10:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
/*
    dynamic_cast es un operador en C++ que se utiliza para convertir un puntero o una referencia
    de un tipo de clase base a un puntero o referencia
    a un tipo de clase derivada. Se usa en herencia y polimorfismo,
    permitiendo verificar y convertir dinámicamente tipos de objetos en tiempo de ejecución.

    dynamic_cast puede usarse para castear un objeto a su propio tipo,
    pero esto es innecesario en la mayoría de los casos, en este caso
    nos es util para poder identificar el tipo de objeto que se esta manejando, ya que si se intenta castear
    un puntero a un tipo que no es, el resultado sera NULL, por lo que se puede usar para identificar el tipo
    de objeto que se esta manejando
    En este caso nos es util para poder identificar el tipo de objeto que se esta manejando
    Porque es diferente la identificacion? por las propias caracteristicas de punteros y referencias:
    *Punteros: 
        La conversión con dynamic_cast devuelve nullptr si falla, permitiendo una simple verificación condicional.
    *Referencias: 
        La conversión con dynamic_cast lanza una excepción std::bad_cast si falla, requiriendo el uso de bloques try-catch.

    
*/
int main(void) {
    
    Base *base;
    base = generate();

    identify(base);

    /*
        Podriamos desreferenciar el puntero primero
        Base& baseRef = *base;
        identify(baseRef);
        y mandar a la funcion que identifica por referencia
        baseRef, pero se puede hacer mas simple usando * al
        mandar el puntero como paremetro, lo desreferenciamos directamente
    */
    identify(*base);
   
    delete base;
    return 0;
}