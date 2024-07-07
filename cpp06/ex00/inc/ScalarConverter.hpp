#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter {
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &rhs);

    public:
    
        static void convert(std::string const &ref);
        static std::string getType(std::string const &ref);

        class ImpossibleConversionException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif