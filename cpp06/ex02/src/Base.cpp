/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:24:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/11 13:21:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

/*******************
*     functions    *
*******************/

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

void identify(Base* p) {
    if(dynamic_cast<A*>(p))
    {
        std::cout << "A class" << std::endl;
        return ;
    }
    if(dynamic_cast<B*>(p))
    {
        std::cout << "B class" << std::endl;
        return ;
    }
    if(dynamic_cast<C*>(p))
    {
        std::cout << "C class" << std::endl;
        return ;
    }
    std::cerr << "Cant identify the class" << std::endl; 
}

