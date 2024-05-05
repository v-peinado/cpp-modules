/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:10:13 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/05 13:23:19 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HHP
#define CLAPTRAP_HHP

#include <iostream>
#include <string>

/*
* Cambios realizados:
 - La parte privada se ha cambiado a protected para que las clases hijas puedan acceder a los atributos.
 - El destructor se ha cambiado a virtual para que las clases hijas puedan sobreescribirlo.
 -Antes de llamar al contructor de la clase derivada, se llama al constructor de la clase base ya que la clase base es la que inicializa los atributos.
 -Primero se llama al destructor de la clase derivada para asegurar que cualquier recurso asignado por las clases derivadas se libere antes de destruir las partes base del objeto
 - Sin un destructor virtual en la clase base, si destruyes un objeto derivado a través de un puntero a la clase base, solo se llamará al destructor de la clase base,
  dejando el destructor de la clase derivada sin llamar. Esto puede llevar a fugas de memoria, recursos no liberados o comportamiento inesperado.
  ejemplo:
    ClapTrap *a = new ScavTrap("Player1");
    delete a;
    En este caso, si el destructor de ClapTrap no es virtual, solo se llamará al destructor de ClapTrap y no al destructor de ScavTrap.
*/

class ClapTrap
{
    protected:
        std::string _name;
        int _hitpoints;
        int _energyPoints;
        int _attackDamage;
    public:
        ClapTrap(std::string name);
        virtual ~ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &rhs);

        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttackDamage(int damage);
        int getAttackDamage();   
};



#endif