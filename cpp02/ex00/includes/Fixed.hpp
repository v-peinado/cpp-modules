/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:39:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/15 21:12:26 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _fixedPoint; //Variable que almacena el valor en punto fijo
        static const int _fractionalBits = 8; //Número de bits fraccionales
    public:
        Fixed(); //Constructor por defecto
        Fixed(const Fixed &copy); //Constructor por copia
        Fixed &operator=(const Fixed &copy); //Operador de asignación, se utiliza para asignar el valor de un objeto a otro objeto del mismo tipo
        ~Fixed(); //Destructor
        int getRawBits(void) const; //Devuelve el valor en punto fijo
        void setRawBits(int const raw); //Establece el valor en punto fijo
};


#endif