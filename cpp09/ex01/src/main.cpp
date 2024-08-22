/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:15:52 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/22 21:55:48 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        std::cerr << "Usage: ./btc [input file]" << std::endl;
        return 1;
    }
    std::string argument(argv[1]);
    RPN rpn(argument);
    try {
        rpn.calculate();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}