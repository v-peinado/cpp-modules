/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:14:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 15:48:05 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
    -Namespaces: son espacios de nombres que permiten organizar el código en grupos lógicos.
                std: es el espacio de nombres estándar de C++. 
                Todas las clases, funciones y objetos de la biblioteca estándar de C++ están definidos dentro del espacio de nombres std.
                Y cuando se se quiere llamar a una función de la biblioteca estándar de C++, se debe anteponer std:: al nombre de la función.
                Lo mismo ocurre con los objetos y clases. Puedes no,brar a dos metodos iguales en diferentes namespaces, o clases.
    -Iterators: son objetos que se utilizan para recorrer secuencias de elementos.
                Se utilizan para apuntar a los elementos de contenedores como arrays, listas, vectores, etc.
                Se pueden mover hacia adelante y hacia atrás a través de la secuencia de elementos.
                Mas versatil que usar indices que solo se pueden usar en arrays.
    -std::string: es una clase que representa una secuencia de caracteres.
    -Std::cout: es un objeto de flujo de salida que se utiliza para imprimir texto en la consola.
*/

int main(int argc, char **argv)
{
    std::string message;
    
    if(argc == 1)
        message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
        message += argv[i];
    for (std::string::iterator it = message.begin(); it != message.end(); it++)
        *it = std::toupper(*it);
    std::cout << message << std::endl;
    return (0);
}
