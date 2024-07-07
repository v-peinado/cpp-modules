#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter {
    private:

        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ~ScalarConverter();
        ScalarConverter & operator=(ScalarConverter const & rhs);

    public:
    
        static void convert(std::string const &ref);

        class ImpossibleConversionException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif