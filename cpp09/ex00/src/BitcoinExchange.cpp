/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/07 17:34:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

/*******************************
 * Constructors and destructors *
 *******************************/

BitcoinExchange::BitcoinExchange()
{
    _data = std::map<std::string, double>();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    _data = rhs._data;
    return *this;
}

/**************************
 *      Member Functions   *
 **************************/

void BitcoinExchange::printDb() const
{
    std::map<std::string, double>::const_iterator it;
    for (it = _data.begin(); it != _data.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

std::string BitcoinExchange::to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

bool BitcoinExchange::is_leap(int year)
{
    // Primero, verifica si el año es divisible por 4
    if (year % 4 == 0)
    {
        // Si el año es divisible por 4, verifica si también es divisible por 100
        if (year % 100 == 0)
        {
            // Si el año es divisible por 100, verifica si también es divisible por 400
            if (year % 400 == 0)
            {
                // Si el año es divisible por 400, entonces es un año bisiesto
                return true;
            }
            else
            {
                // Si el año es divisible por 100 pero no por 400, entonces no es un año bisiesto
                return false;
            }
        }
        else
        {
            // Si el año es divisible por 4 pero no por 100, entonces es un año bisiesto
            return true;
        }
    }
    else
    {
        // Si el año no es divisible por 4, entonces no es un año bisiesto
        return false;
    }
}

void BitcoinExchange::is_valid_date(std::string date, std::string filename, int i)
{
    int year, month, day;
    char delimiter1, delimiter2;
    std::stringstream ss(date);

    if (!(ss >> year >> delimiter1 >> month >> delimiter2 >> day) || delimiter1 != '-' || delimiter2 != '-' || ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid date format in file " + filename + " at line " + to_string(i) + " => " + date);
    if (year < 2009)
        throw std::runtime_error("Error: the year cannot be less than 2009 in file " + filename + " at line " + to_string(i) + " => " + date);
    if (year > 2024)
        throw std::runtime_error("Error: the year cannot be greater than 2024 in file " + filename + " at line " + to_string(i) + " => " + date);
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: the month must be between 1 and 12 in file " + filename + " at line " + to_string(i) + " => " + date);
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
        throw std::runtime_error("Error: the day must be between 1 and 31 in file " + filename + " at line " + to_string(i) + " => " + date);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
        throw std::runtime_error("Error: the day must be between 1 and 30 in file " + filename + " at line " + to_string(i) + " => " + date);
    if (month == 2 && is_leap(year) && (day < 1 || day > 29))
        throw std::runtime_error("Error: the day must be between 1 and 29 in file " + filename + " at line " + to_string(i) + " => " + date);
    if (month == 2 && !is_leap(year) && (day < 1 || day > 28))
        throw std::runtime_error("Error: the day must be between 1 and 28 in file " + filename + " at line " + to_string(i) + " => " + date);
}

void BitcoinExchange::validLineDB(std::string line, std::string filename, int i)
{
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, ',');
    ss >> value;
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid exchange rate format in file " + filename + " at line " + to_string(i) + " => " + line);
    this->_data[key] = value;
}

void BitcoinExchange::validLineInput(std::string line, std::string filename, int i)
{
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, '|');
    ss >> value;
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (value > 1000)
        throw std::runtime_error("Error: the value cannot be greater than 1000 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid value format in file " + filename + " at line " + to_string(i) + " => " + line);
    if (_data.find(key) != _data.end())
    {
        std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
    }
    else
    {
        std::map<std::string, double>::iterator it = _data.lower_bound(key); // Buscamos la fecha mas cercana por debajo
        if (it == _data.begin())                                             // Si no hay fecha por debajo, lanzamos una excepción
            throw std::runtime_error("Error: no exchange rate data available for date " + key + " in file " + filename + " at line " + to_string(i) + " => " + line);
        else
        {
            it--;
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        }
    }
}

void BitcoinExchange::parseDbFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
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
    while (std::getline(file, line))
    {
        i++; // Para saber en que linea estamos
        std::stringstream ss(line);
        if (line.empty())
            continue;
        try
        {
            validLineDB(line, filename, i);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    // printDb(); //Para comprobar que se ha rellenado correctamente
    file.close();
}

void BitcoinExchange::parseInputFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
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
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    /*
        Leemos el archivo linea por linea y guardamos los datos en un map
        Parsearemos si la linea no esta vacia y si el formato es correcto,
        si no, lanzaremos una excepción, sin salir del programa
    */
    while (std::getline(file, line))
    {
        i++; // Para saber en que linea estamos
        std::stringstream ss(line);
        if (line.empty())
            continue;
        /*
            Eliminamos los espacios en blanco de la linea usando el metodo erase y remove_if, iterando sobre la linea y borrndo los espacios
            Parseamos la linea y guardamos la fecha y el valor en dos variables con getline, poniendo como delimitador el caracter '|'
            obtendremps key que sera lo que haya antes del delimitador y el resto de ss lo guardaremos en value usando el operador >>
            que  nos permite convertir el resto de la linea a double
            Si la linea no es valida, lanzamos una excepción especifica y continuamos con la siguiente linea
        */
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        // Si la linea no es valida, lanzamos una excepción especifica y continuamos con la siguiente linea
        try
        {
            validLineInput(line, filename, i);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    file.close();
}
