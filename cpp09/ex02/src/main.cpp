/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:11 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/25 00:35:16 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./PmergeMe [string]" << std::endl;
        return 1;
    }
    std::string str = argv[1];
    PmergeMe pmm(str);
    pmm.init();
    return 0;
}