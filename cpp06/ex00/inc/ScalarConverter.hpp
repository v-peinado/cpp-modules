#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>

class ScalarConverter {
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &rhs);

    public:
    
        static void convert(std::string const &ref);

        class ImpossibleConversionException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::string getType(std::string const &ref);
bool isInt(std::string const &ref);
bool isFloat(std::string const &ref);
bool isDouble(std::string const &ref);
void printChar(std::string const &ref);
void printInt(std::string const &ref);
void printFloat(std::string const &ref);
void printDouble(std::string const &ref);
void printPseudoDouble(std::string const &ref);
void printPseudoFloat(std::string const &ref);

#endif