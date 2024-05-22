/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:34:57 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/13 17:27:27 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/*
Las reglas básicas de la Orthodox Canonical Form en C++ incluyen:
-Constructor por defecto: La clase debe proporcionar un constructor por defecto que inicialice el objeto en un estado válido.
        ejemplo: Fixed a; --> Constructor por defecto
-Constructor de copia: Debe haber un constructor de copia que permita crear una nueva instancia de la clase a partir de otra ya existente. 
                        El constructor de copia debe copiar todos los miembros de la clase.
                        y no debe compartir recursos con el objeto original.
                        Copia los valores de los atributos de un objeto a otro objeto.
        ejemplo de uso: Fixed a; --> Contructor pord efecto
                        Fixed b(a); --> Constructor de copia
-Operador de asignación: Debe proporcionarse un operador de asignación (operator=) que permita asignar el valor de un objeto a otro objeto de la misma clase.
        ejemplo de uso: Fixed a; --> Constructor por defecto
                        Fixed b; --> Constructor por defecto
                        b = a; --> Operador de asignación
-Destructor: Se debe proporcionar un destructor para liberar cualquier recurso adquirido por el objeto.

Fixed point o punto fijo es una forma de representar números fraccionarios.
En un número en punto fijo, un número entero se representa con una parte entera y una parte fraccionaria.
La parte entera se almacena en los bits más significativos y la parte fraccionaria en los bits menos significativos.
En este caso, se almacena en 8 bits la parte fraccionaria.
8 bits para la parte fraccionaria significa que se pueden representar 256 valores diferentes.
2 elevado a -8 es igual a 1/256, por lo que el valor de la parte fraccionaria es 1/256 = 0.00390625.
Los numeros de punto fijo se utilizan en aplicaciones donde se necesita mayor rendimiento, sacrificando precisión, al limitar
la parte decimal pero favorecer los calculos con enteros.
*/

int main( void ) {
    Fixed a;
    Fixed b( a ); 
    Fixed c;
    c = b;
    std::cout << a.getFixed() << std::endl;
    std::cout << b.getFixed() << std::endl;
    std::cout << c.getFixed() << std::endl;
    return 0;
}