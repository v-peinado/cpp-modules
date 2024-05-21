/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:35:33 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/20 21:13:02 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HHP
#define DIAMONDTRAP_HHP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

 /* 
    - Problema del diamante: Surgue cuando una clase hereda de dos clases que a su vez comparte una clase en común.
        En este caso, la clase DiamondTrap hereda de ScavTrap y FragTrap, y ambas heredan de ClapTrap.
        Para solucionar este problema, se debe usar la herencia virtual y evitar la ambigüedad y la duplicación de instancias de la clase ClapTrap.
        
    - Using: especificamos que vamos a usar la funcion attack de la clase ScavTrap

    -En el constructor de la clase DiamondTrap, se debe pasar el nombre a las clases ScavTrap y FragTrap,
     ya que ambas clases tienen un constructor que recibe un string. Y en C++, cada vez que se crea una clase deriva de otra, se llama al constructor de la clase base.

    -Surge tambien el problema de la asignacion de los valores de la clase DiamondTrap, ya que esta hereda de dos clases, ScavTrap y FragTrap, y ambas heredan de ClapTrap.
     Para evitar que se sobreescriban los valores al asignarlos
    _hitpoints = FragTrap::_hitpoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    La ultima asignacion de los valores de la clase base se hace a la clase FragTrap, ya que es la ultima clase de la que se hereda. 
    Esto lo solucionamos creando variables estaticas en las clases ScavTrap y FragTrap,
     y asignando los valores de la clase base a estas variables.
    
*/

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &rhs);

        void getValues();
        
        using ScavTrap::attack;
        void whoAmI();
};

#endif