/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:19:56 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/12 12:31:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
    Este ejercicio es bastante parecido al anterior, pero se imprimiran todos los mensajes a partir del nivel que se le pase como argumento.
    Para ello, necesitamos que el switch tenga un case por cada nivel de log, pero no solo imprima el mensaje,
     sino que siga avanzando e imprima todos los casos siguientes.
    Para ello se usa // fallthrough, que hace que el switch siga ejecutando los casos siguientes.
    // fallthrough se usa para que el switch siga ejecutando los casos siguientes, 
    En C++17 se puede usar [[fallthrough]] para indicar que se quiere que el switch siga ejecutando los casos siguientes.
*/

int main(int argc, char *argv[]) {
    Harl Harl;
    if (argc == 2)
    {
        std::string prompt;
        Harl.complain(argv[1]);
    }
    else
        std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    return (0);
}