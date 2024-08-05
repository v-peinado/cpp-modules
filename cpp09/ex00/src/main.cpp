/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/05 17:50:32 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        std::cout << "Usage: ./btc [input file]" << std::endl;
        return 1;
    }
    filename = argv[1];
    BitcoinExchange exchange = BitcoinExchange();
    exchange.startExchange(filename);
    return 0;
}