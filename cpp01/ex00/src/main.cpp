/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:45:56 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/07 15:45:13 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/*
casos en el que usar heap: 
    - cuando necesitamos que el objeto siga existiendo despues de que la funcion termine, ya que el heap no se libera hasta que se llame a delete
    - cuando el objeto es grande, o desconocemos su tamaño y podria ser grande
casos en el que usar stack:
    - cuando solo necesitamos que el objeto exista durante la ejecucion de la funcion, ya que el stack se libera automaticamente al terminar la funcion
    - cuando el objeto es pequeño
    - cuando el objeto no necesita ser compartido
    - cuando el objeto no necesita ser grande, ya que el stack es limitado y se podria dar un stack overflow, o desbordamiento de pila
Cuando el zombie es creado en heap, se necesita llamar a delete para liberar la memoria, ya que si no se hace, se crea un leak de memoria
Al crear un zombie en stack, no es necesario llamar a delete, ya que la memoria se libera automaticamente al terminar la funcion en la que se creo
*/
int main(void)
{
    std::cout << "********HEAP********" << std::endl;
    Zombie *heap_zombie = newZombie("heap_zombie");
    heap_zombie->announce();
    delete heap_zombie;
    
    std::cout << "********STACK*******" << std::endl;
    randomChump("stack_zombie");
    return 0;
}