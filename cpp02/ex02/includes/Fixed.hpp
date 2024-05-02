/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:24 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/19 19:31:09 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

/*
La sobrecarga de oepradores es una técnica que permite a los programadores definir el comportamiento de los operadores en clases personalizadas.
En este caso, se sobrecargan los operadores +, -, *, /, ++, --, >, <, >=, <=, ==, !=, << y >>.
Antertiormente, se sobrecargaron los operadores = y <<.
*/
class Fixed {
    private:
    
        int _fixedPoint; //Variable que almacena el valor en punto fijo
        static const int _fractionalBits = 8; //Número de bits fraccionales
    public:
    
        Fixed(); //Constructor por defecto
        Fixed(const int value); 
        Fixed(const float value);

        Fixed(const Fixed &copy);
        

        //=========Sobrecarga de operadores===========//
        
        //Operador de asignación
         Fixed &operator=(const Fixed &value);
        
        //Operadores aritméticos
        Fixed operator+(const Fixed &value) const;
        Fixed operator-(const Fixed &value) const;
        Fixed operator*(const Fixed &value) const;
        Fixed operator/(const Fixed &value) const;

        //Operadores de incremento y decremento
        Fixed &operator++(void); //Pre-incremento
        Fixed operator++(int);
        Fixed &operator--(void); //Pre-decremento
        Fixed operator--(int);

        //Operadores de comparación
        bool operator>(const Fixed &value) const;
        bool operator<(const Fixed &value) const;
        bool operator>=(const Fixed &value) const;
        bool operator<=(const Fixed &value) const;
        bool operator==(const Fixed &value) const;
        bool operator!=(const Fixed &value) const;
        
        
    
        ~Fixed(); //Destructor
        
        int getRawBits(void) const; //Devuelve el valor en punto fijo
        void setRawBits(int const raw); //Establece el valor en punto fijo
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
    };

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif