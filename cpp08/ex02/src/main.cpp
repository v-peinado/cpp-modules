/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:36 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/25 22:29:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(42);

    std::cout << "******************************" << std::endl
              << "Testing with MutantStack<int>:" << std::endl
              << "******************************" << std::endl;
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);

    std::cout << "MutantStack reverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
        std::cout << *it << " ";
    std::endl(std::cout);
    return 0;
}