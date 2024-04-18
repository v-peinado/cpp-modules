/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:30:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/18 22:43:49 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	++a;
	std::cout << "Imprime 0.00390625 porque 1 << 8 = 256 y 1/256 = 0.00390625"<< std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "imprime 0.00390625, al ser post-incremento, primero imprime el valor de a y luego lo incrementa"<< std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "MAX(a,b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "MIN(a,b) = " << Fixed::min( a, b ) << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	return 0;

}