/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:57:27 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/10 19:29:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(std::string type); // significa que el constructor de la clase 'Weapon' recibe un parámetro de tipo 'std::string' y lo asigna a la variable miembro 'type' de la clase.
        ~Weapon(); // significa que el destructor de la clase 'Weapon' no recibe parámetros y no hace nada (porque no hay código en su definición
        const std::string& getType() const; // significa que la función devuelve una referencia a la variable miembro 'type' de la clase, pero esta referencia no puede utilizarse para modificar el valor de 'type'. Los : const al final de la declaración de la función indican que la función no modificará el objeto al que pertenece.
        void setType(std::string type); // significa que la función recibe un parámetro de tipo 'std::string' y lo asigna a la variable miembro 'type' de la clase.
};

#endif