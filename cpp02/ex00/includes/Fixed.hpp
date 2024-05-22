/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:39:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/22 20:04:25 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        /*
        Especifica cuántos bits se deben usar para representar la porción decimal de un entero binario o un valor de punto flotante.
        En realidad estamos trabajajando con binarios, 
        por lo que se puede considerar que los primeros 24 bits se expresan como el componente entero 
        y los últimos 8 bits se expresan como la parte decimal en el sistema de 32 bits si los bits fraccionarios se establecen en 8 bits.
        */
        int _fixedPoint; //Variable que almacena el valor en punto fijo
        static const int _fractionalBits = 8; //Número de bits fraccionales
    public:
        Fixed(); //Constructor por defecto
        Fixed(const Fixed &copy); //Constructor por copia, se usa una referencia porque si se hace copia por valor se llamaría al constructor de copia de nuevo, creando un bucle infinito
        Fixed &operator=(const Fixed &copy); //Operador de asignación, se utiliza para asignar el valor de un objeto a otro objeto del mismo tipo
        ~Fixed(); //Destructor
        int getFixed(void) const; //Devuelve el valor en punto fijo
        void setFixed(int const raw); //Establece el valor en punto fijo
};


#endif