#include "ScalarConverter.hpp"

/***************
* Constructors *
***************/

/*
    En este ejercicio no se podra instanciar un objeto de la clase,
    lo que se hara es llamar a la funcion convert que sera estatica, esto
    significa que no se podra acceder a los atributos de la clase(si tuviese),
    y no depende de una instancia de clase para ser llamada.
    No necesitaremos un constructor, destructor, ni operador de asignacion, lo declararemos
    como privado para que no se pueda instanciar un objeto de la clase.

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}*/

/*********************
* Exceptions classes *
*********************/


const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
    return "impossible";
}

/*******************
* Member functions *
*******************/

std::string ScalarConverter::getType(std::string const &ref)
{
    std::string type = "char";

    if(ref == "inff" || ref == "+inff" || ref == "-inff" || ref == "nanf")
        type = "pseudo_f";
    else if(ref == "inf" || ref == "+inf" || ref == "-inf" || ref == "nan")
        type = "pseudo_d";
    else
    {
        size_t i = 0;
        for(i = 0; i < ref.length(); i++)
        {
            if(ref[i] == '.')
                break;
        }
        if(i == ref.length())
        {
            for(i = 0; i < ref.length(); i++)
            {
                if(ref[i] == 'f')
                    break;
            }
            if(i == ref.length())
                type = "int";
            else
                type = "float";
        }
        else
        {
            for(i = 0; i < ref.length(); i++)
            {
                if(ref[i] == 'f')
                    break;
            }
            if(i == ref.length())
                type = "double";
            else
                type = "float";
        }
    }
    return type;
}

void ScalarConverter::convert(std::string const &ref)
{
    std::string type = ScalarConverter::getType(ref);
    std::string types[] = { "char", "int", "float", "double", "pseudo_f", "pseudo_d"};
    int i = 0;
    for(i = 0; i < 4; i++)
        if(type == types[i])
            break;
    switch (i)
    {
        case 0:
            std::cout << "char: ";
            //ScalarConverter::printChar(ref);
            break;
        case 1:
            std::cout << "int: ";
            //ScalarConverter::printInt(ref);
            break;
        case 2:
            std::cout << "float: ";
            //ScalarConverter::printFloat(ref);
            break;
        case 3:
            std::cout << "double: ";
            //ScalarConverter::printDouble(ref);
            break;
        case 4:
            std::cout << "psefloat: ";
            //ScalarConverter::printPseudoFloat(ref);
            break;
        case 5:
            std::cout << "psedouble: ";
            //ScalarConverter::printPseudoDouble(ref);
            break;
        default:
            throw ScalarConverter::ImpossibleConversionException();
    }
}