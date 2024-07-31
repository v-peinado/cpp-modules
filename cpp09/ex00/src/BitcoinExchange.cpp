/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/31 14:26:48 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*******************************
* Constructors and destructors *
*******************************/

BitcoinExchange::BitcoinExchange() {
    _data = std::map<std::string, double>();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    _data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    _data = rhs._data;
    return *this;
}







/**************************
*      Member Functions   *
**************************/


