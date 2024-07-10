/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:24:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/10 14:38:09 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base * generate() {
    std::srand(time(NULL));
    switch (rand() % 3)
    {
    case 0:
        std::cout << "New A" << std::endl;
        return new A;
    case 1:
        std::cout << "New B" << std::endl;
        return new B;
    case 2:
        std::cout << "New C" << std::endl;
        return new C;    
    default:
        std::cerr << "ERROR!!!!\n";
        return NULL;
        break;
    }
}