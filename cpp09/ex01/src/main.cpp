/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:15:52 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/27 21:11:00 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./RPN [list of numbers]" << std::endl;
        return 1;
    } 
    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str += argv[i];
        if (i < argc - 1)
            str += " ";
    }
    
    RPN rpn(str);
    try {
        rpn.calculate();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}