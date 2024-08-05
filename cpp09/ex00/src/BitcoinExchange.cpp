/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/05 19:48:58 by vpeinado         ###   ########.fr       */
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

bool BitcoinExchange::is_leap(int year) {
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

void BitcoinExchange::is_valid_date(std::string date, std::string filename, int i) {
    int year, month, day;
    std::stringstream ss(date);
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    if (year < 2009)
        throw std::runtime_error("Error: the year cannot be less than 2009 in file " + filename + " at line " + to_string(i));
    if (year > 2024)
        throw std::runtime_error("Error: the year cannot be greater than 2024 in file " + filename + " at line " + to_string(i));
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: the month must be between 1 and 12 in file " + filename + " at line " + to_string(i));
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
        throw std::runtime_error("Error: the day must be between 1 and 31 in file " + filename + " at line " + to_string(i));
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
        throw std::runtime_error("Error: the day must be between 1 and 30 in file " + filename + " at line " + to_string(i));
    if (month == 2 && is_leap(year) && (day < 1 || day > 29))
        throw std::runtime_error("Error: the day must be between 1 and 29 in file " + filename + " at line " + to_string(i));
    if (month == 2 && !is_leap(year) && (day < 1 || day > 28))
        throw std::runtime_error("Error: the day must be between 1 and 28 in file " + filename + " at line " + to_string(i));
}

void BitcoinExchange::validLineDB(std::string line, std::string filename, int i) {
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, ',');
    ss >> value;
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0  in file " + filename + " at line " + to_string(i));
}

void BitcoinExchange::validLineInput(std::string line, std::string filename, int i) {
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, '|');
    ss >> value;
    is_valid_date(key, filename, i); 
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0  in file " + filename + " at line " + to_string(i));
    if (value > 1000)
        throw std::runtime_error("Error: the value cannot be greater than 1000 in file " + filename + " at line " + to_string(i));
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
            validLineDB(line, filename, i);
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
        std::getline(ss, key, '|');
        ss >> value;
        //Si la linea no es valida, lanzamos una excepción especifica y continuamos con la siguiente linea
        try
        {
            validLineInput(line, filename, i);           
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        //Si encontramos conincidencia en la fecha, multiplicamos el valor de btc por el valor de la moneda, si no buscamos la fecha mas cercana por debajo
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