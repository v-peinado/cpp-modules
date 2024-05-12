/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:19:56 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/12 12:13:11 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
    Array de punteros a funciones:
    - Se crea un array de punteros a funciones que reciben un string y no devuelven nada.
      Crearemos una funcion llamada complain(queja) que recibe un string, que sera el level debug, info, warning o error.
    - Se crea un array de strings con los niveles de log para comparar y segun el indice ejecutar la funcion correspondiente
        Hacemos esto para poder comparar el string que se pasa por parametro con los strings del array y ejecutar la funcion correspondiente
        y evitar tener que hacer un if por cada nivel de log.
        Asi hallamos el indice del string que se pasa por parametro en el array de strings y ejecutamos la funcion que esta en el mismo indice,
        usamos switch que ademas solo puede recibir enteros, usando el indice para los cases del switch.
*/

int main(void) {
    Harl Harl;
    std::string prompt;
    while(!(prompt.compare("EXIT") == 0 || std::cin.eof()))
    {
        std::cout << ">";
        std::getline(std::cin, prompt);
        Harl.complain(prompt);
    }
    return (0);
}