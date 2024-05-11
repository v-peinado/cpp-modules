/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 16:03:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8]; // Array de punteros a Contact, maximo 8 contactos
        int _maxIndex; // Indice maximo que se ha guardado, si es mas 8, se sobreescribira el primer contacto
        int oldestContact(Contact contacts[]); // Devuelve el indice del contacto mas antiguo, el que sera sobreescrito
    public:
        PhoneBook(); // Constructor, crear un array de 8 punteros a Contact, inicializar _index a 0 y _size a 0
        ~PhoneBook(); // Destructor, liberar la memoria de los punteros a Contact
        void addContact();
        void searchContact();
};

#endif
