/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/02 13:35:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

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

void BitcoinExchange::printDb() const {
    std::map<std::string, double>::const_iterator it;
    for (it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void BitcoinExchange::parseDbFile(std::string filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    std::string key;
    double value;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file " + filename);
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error: invalid header format in file " + filename);
    //Despues de comprobar el encabezado seguimos con el resto del archivo
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, key, ',');
        ss >> value;
        this->_data[key] = value;
    }
    printDb();
}

void BitcoinExchange::startExchange(std::string filename) {
    parseDbFile("data.csv");
    (void)filename;
   // parseInputFile(filename);
}