/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/22 19:32:40 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
   Punto fijo:
   Especifica cuántos bits se deben usar para representar la porción decimal de un entero binario o un valor de punto flotante.
    Los primeros 24 bits se expresan como el componente entero y los últimos 8 bits se expresan como la parte decimal en el sistema de 32 bits 
    si los bits fraccionarios se establecen en 8 bits.
    Es decir para la parte entera se reserva 2^24() y para la parte decimal 2^-8 o 1/256.
*/

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}