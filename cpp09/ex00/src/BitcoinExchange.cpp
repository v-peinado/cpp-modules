/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/05 18:36:30 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

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

std::string BitcoinExchange::to_string(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

// bool BitcoinExchange::is_valid_date(std::string date) {
    
// }

bool BitcoinExchange::invalidLineDB(std::string line) {
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, ',');
    ss >> value;
    //if(!is_valid_date(key))
        //return true;
    if (ss.fail() || !ss.eof())
        return true;
    return false;
}

void BitcoinExchange::parseDbFile(std::string filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
    std::string date;
    double value;
    
    /* 
        Comprobamos si el archivo existe y el encabezado es correcto
        Si no, lanzamos una excepción y saldre del programa
    */
    try 
    {
        if (!file.is_open())
            throw std::runtime_error("Error: could not open file " + filename);
        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw std::runtime_error("Error: invalid header format in file " + filename);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    /*
        Leemos el archivo linea por linea y guardamos los datos en un map
        Parsearemos si la linea no esta vacia y si el formato es correcto,
        si no, lanzaremos una excepción, sin salir del programa
    */
    while (std::getline(file, line)) {
        i++; //Para saber en que linea estamos
        std::stringstream ss(line);
        if (line.empty())
            continue;
        try
        {
            if (invalidLineDB(line))
                throw std::runtime_error("Error: invalid line format in file " + filename + " at line " + to_string(i));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::getline(ss, date, ',');
        ss >> value;
        this->_data[date] = value;
    }
    //printDb(); //Para comprobar que se ha rellenado correctamente
    file.close();
}

void BitcoinExchange::parseInputFile(std::string filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
    std::string key;
    double value;

    /* 
        Comprobamos si el archivo existe y el encabezado es correcto
        Si no, lanzamos una excepción y saldre del programa
    */
    try
    {
        if (!file.is_open())
            throw std::runtime_error("Error: could not open file " + filename);
        std::getline(file, line);
        if (line != "date | value")
            throw std::runtime_error("Error: invalid header format in file " + filename);  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    /*
        Leemos el archivo linea por linea y guardamos los datos en un map
        Parsearemos si la linea no esta vacia y si el formato es correcto,
        si no, lanzaremos una excepción, sin salir del programa
    */    
    while (std::getline(file, line)) {
        i++; //Para saber en que linea estamos
        std::stringstream ss(line);
        if (line.empty())
            continue;
        //if (invalidLineFormat(line))
            //throw std::runtime_error("Error: invalid line format in file " + filename + " at line " + to_string(i));
        std::getline(ss, key, '|');
        ss >> value;
        try
        {
            if (_data.find(key) == _data.end())
                throw std::runtime_error("Error: date not found in " + filename + " at line " + to_string(i));              
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        //Si encontramos conincidencia en la fecha, multiplicamos el valor de btc por el valor de la moneda
        if (_data.find(key) != _data.end())
        {
            std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::startExchange(std::string filename) {
    parseDbFile("data.csv");
    parseInputFile(filename);
}