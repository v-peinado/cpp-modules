/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:38:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 16:38:15 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
Conceptos:
    Punteros:
    Un puntero es una variable que almacena la dirección de memoria de otra variable.
    Se declara utilizando el operador *.
    Se utiliza para acceder y manipular los datos a los que apunta.
    Pueden ser nulos, lo que significa que no apuntan a ninguna dirección de memoria válida.
    Se pueden utilizar para la gestión dinámica de la memoria, como la asignación y liberación de memoria en tiempo de ejecución.

Referencias:
    Una referencia es un alias (otro nombre) para una variable existente.
    Se declara utilizando el operador &.
    Se utiliza para acceder y manipular directamente los datos de la variable original.
    No puede ser nula, debe referirse a una variable válida.
    No puede ser reasignada después de su inicialización.
    Proporciona una sintaxis más clara y concisa en comparación con los punteros.

En C, no hay un concepto directo de referencias como en C++. En C++,
además de obtener la dirección de memoria de una variable,
el operador & también se utiliza para declarar y trabajar con referencias
*/

int main() {
    std::string str = "HI THIS IS BRAIN"; // Creo un string
    std::string* stringPTR = &str; // Creo un puntero a string
    std::string& stringREF = str; // Creo una referencia a string

    std::cout << "Direcciones de memoria" << std::endl;
    std::cout << &str << std::endl; //Obtengo la dirección de memoria de str
    std::cout << stringPTR << std::endl; //Obtengo la dirección de memoria guardada en el puntero stringPTR
    std::cout << &stringREF << std::endl; //Obtengo la dirección de memoria de la referencia stringREF, stringREF es un alias de str

    std::cout << "Valores"<< std::endl;
    std::cout << str << std::endl; //Imprimo el valor de str
    std::cout << *stringPTR << std::endl; //Imprimo el valor al que apunta el puntero stringPTR
    std::cout << stringREF << std::endl; //Imprimo el valor de la referencia stringREF, stringREF es un alias de str

    return 0;
}