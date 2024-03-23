/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/23 00:59:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact *_contacts[7]; // Array de punteros a Contact, maximo 8 contactos
        int     _index; // Indice para saber en que posicion del array estamos
        int     _nbrContacs; // Tamaño del array

    public:
        PhoneBook(); // Constructor, crear un array de 8 punteros a Contact, inicializar _index a 0 y _size a 0
        ~PhoneBook(); // Destructor, liberar la memoria de los punteros a Contact

        void addContact();
        void searchContact();
        void printContact();
};

#endif
