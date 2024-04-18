/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:24 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/18 12:54:09 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
    
        int _fixedPoint; //Variable que almacena el valor en punto fijo
        static const int _fractionalBits = 8; //Número de bits fraccionales
    public:
    
        Fixed(); //Constructor por defecto
        Fixed(const int value); 
        Fixed(const float value);

        Fixed(const Fixed &copy);
        
        Fixed &operator=(const Fixed &copy);
        
        ~Fixed(); //Destructor
        
        int getRawBits(void) const; //Devuelve el valor en punto fijo
        void setRawBits(int const raw); //Establece el valor en punto fijo
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif