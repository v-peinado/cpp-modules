/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:00:50 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 14:28:20 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &rhs);

        
        virtual void makeSound() const = 0; //porque const = 0? porque es una funcion pura virtual y eso significa que no tiene implementacion en la clase base
        const std::string& getType() const;
};

#endif