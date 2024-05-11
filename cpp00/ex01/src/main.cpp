/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:55:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 16:15:56 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
    -Clases: son estructuras de datos que contienen atributos y metodos(variables y funciones) relacionados en un solo bloque logico.
            -Atributos: son variables que pertenecen a una clase.
            -Metodos: son funciones que pertenecen a una clase.
            -Constructores: son metodos que se llaman automaticamente cuando se crea un objeto de una clase.
            -Destructor: es un metodo que se llama automaticamente cuando se destruye un objeto de una clase.
            -Parte publica: es la parte de la clase que se puede acceder desde cualquier parte del programa.
            -Parte privada: es la parte de la clase que solo se puede acceder desde la misma clase.
            -getters y setters: son metodos que se utilizan para acceder y modificar los atributos de una clase.
                En este caso, se han implementado metodos para acceder y modificar los atributos de la clase PhoneBook.
                Aunque no se han nombrado como getters y setters, por claridad en el codigo.
    -Objetos: son instancias de una clase, la clase actua como un "modelo" o esquema y el objeto es una "instancia" de ese modelo.

    En estre programa se ha creado una clase PhoneBook que contiene un array de 8 contactos, y metodos para añadir y buscar contactos.
    Se ha creado una clase Contact que contiene los atributos de un contacto, y metodos para acceder y modificar estos atributos.
    Se ha creado un objeto MyPhoneBook de la clase PhoneBook, que se utiliza para añadir y buscar contactos, contenidos en un array de 8 contactos.
    Utilirizaremos dos indices de contactos, uno que indicara la antiguedad del contacto(maxIndex),
     y otro que indicara el indice del contacto en el array(contactIndex).
    Mientras que el indice de contactos no sea mayor que 8, se podran añadir contactos, 
    agregando un nuevo contacto al array de contactos y usando el maxIndex como indice. Si el indice es mayor que 8, se sobreescribira el primer contacto,
    buscando en maxIndex menor lo que indicara el primer anadido y el candidato a ser sustituido
    
*/

int main (void)
{
    PhoneBook MyPhoneBook;
    std::string prompt;
    while(!(prompt.compare("EXIT") == 0 || std::cin.eof()))
    {
        std::cout << ">";
        std::getline(std::cin, prompt);
        if(prompt.compare("ADD") == 0)
            MyPhoneBook.addContact();
        else if(prompt.compare("SEARCH") == 0)
        {
            MyPhoneBook.searchContact();
        }
            
        else if(prompt.empty())
            continue;
        else
            std::cout << "**Invalid command" << std::endl;
    }
    return (0);
}
