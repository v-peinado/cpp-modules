/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:28 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/26 13:33:26 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

/******************************************************************************
* ------------------------------- CONSTRUCTORS ------------------------------ *
******************************************************************************/

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

/*****************************************************************************
* ------------------------------- MEMBER FUNCTIONS ------------------------- *
*****************************************************************************/

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
    /*
        Usa un stringstream para parsear la fecha y guardarla en las variables year, month y day
        Esto podemos hacerlo debido a que sabemos que la fecha tiene un formato especifico, de numeros separados por guiones(char)
        Si la fecha no tiene el formato correcto, lanzamos una excepción
        El control de flujo se hace de la siguiente manera:
        - Si no se puede parsear la fecha, lanzamos una excepción
        - Si el primer delimitador no es un guion, lanzamos una excepción
        - Si el segundo delimitador no es un guion, lanzamos una excepción
        - Si el flujo de datos falla, lanzamos una excepción
        - Si no se ha llegado al final del flujo de datos, lanzamos una excepción
        Razones por las ss puede dar fail() o no estar en eof():
        - Si la fecha no tiene el formato correcto, ss no podra parsearla y dara fail()
        - Si la fecha tiene mas de dos guiones, ss no podra parsearla y dara fail()
        - Si la fecha tiene menos de dos guiones, ss no podra parsearla y dara fail()
        Hay casos especificos que no dara fail pero no llegara al final del flujo de datos:
        - Si la fecha tiene mas caractreres despues del dia, ss no podra parsearla y no llegara al final del flujo de datos
    */

    
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
    // Parseamos la linea y guardamos la fecha y el valor en dos variables con getline, poniendo como delimitador el caracter ','
    // se guardara en key lo que haya antes del delimitador y el resto de ss lo guardaremos en value usando el operador >> que nos permite convertir el resto de la linea a double
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
    if (line[0] == ' ' || line[0] == '\t') // Si la linea empieza con un espacio o tabulador, lanzamos una excepción
        throw std::runtime_error("Error: the line cannot start with a space in file " + filename + " at line " + to_string(i) + " => " + line);
    /*
        Buscamos la posición del delimitador en la linea " | ", ya que al ser 3 caracteres no podemos usar la mismas formulas que en data.csv
        Si no encontramos el delimitador, lanzamos una excepción
    */
    size_t delimiter_pos = line.find(" | ");
    if (delimiter_pos == std::string::npos)
        throw std::runtime_error("Error: the delimiter \" | \" is not found in file " + filename + " at line " + to_string(i) + " => " + line);
    //iteramos y si encontramos mas de dos espacios en blanco, error
    if (std::count(line.begin(), line.end(), ' ') > 2)
        throw std::runtime_error("Error: the delimiter \" | \" is not found in file " + filename + " at line " + to_string(i) + " => " + line);
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    std::stringstream ss(line);
    /*
        Eliminamos los espacios en blanco de la linea usando el metodo erase y remove_if, iterando sobre la linea y borrndo los espacios
        Parseamos la linea y guardamos la fecha y el valor en dos variables con getline, poniendo como delimitador el caracter '|'
        obtendremps key que sera lo que haya antes del delimitador y el resto de ss lo guardaremos en value usando el operador >>
        que  nos permite convertir el resto de la linea a double
        Si la linea no es valida, lanzamos una excepción especifica y continuamos con la siguiente linea
    */
    std::string key;
    double value;
    std::getline(ss, key, '|'); // obtenemos la fecha, en key se guardara lo que hay antes del delimitador "|"
    ss >> value; //El resto de la linea se guarda en value, que sera el valor de la moneda
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (value > 1000)
        throw std::runtime_error("Error: the value cannot be greater than 1000 in file " + filename + " at line " + to_string(i) + " => " + line);
    //Si la conversion falla o no hemos llegado al final del flujo de datos, lanzamos una excepción
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid value format in file " + filename + " at line " + to_string(i) + " => " + line);
    //Con find buscamos la fecha en el map, si la encontramos antes de llegar al final del map, imprimimos el resultado
    if (_data.find(key) != _data.end())
    {
        std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
    }
    else
    {
        // Al estas las fechas en formato "YYYY-MM-DD" podemos usar lower_bound para buscar la fecha anterior
        std::map<std::string, double>::iterator it = _data.lower_bound(key); // lower_bound nos devuelve un iterador al primer elemento que no es menor que key, luego haremos it--
        if (it == _data.begin()) // significa que la clave key que buscas es menor o igual a la primera clave en el mapa y lower_bound devuelve begin()
            throw std::runtime_error("Error: no exchange rate data available for date " + key + " in file " + filename + " at line " + to_string(i) + " => " + line);
        else
        {
            //it apunta al primer elemento que no es menor que key, por lo que debemos retroceder para obtener la fecha anterior
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
        if (line.empty())
            continue;
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
