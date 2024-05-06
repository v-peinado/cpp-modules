/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:35:33 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/06 20:11:27 by vpeinado         ###   ########.fr       */
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
        
        using ScavTrap::attack;
        void whoAmI();
};

#endif