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
        static std::string getType(std::string const &ref);
        static bool isInt(std::string const &ref);
        static bool isFloat(std::string const &ref);
        static bool isDouble(std::string const &ref);
        static void printChar(std::string const &ref);
        static void printInt(std::string const &ref);
        static void printFloat(std::string const &ref);
        static void printDouble(std::string const &ref);
        static void printPseudoDouble(std::string const &ref);
        static void printPseudoFloat(std::string const &ref);

        class ImpossibleConversionException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif