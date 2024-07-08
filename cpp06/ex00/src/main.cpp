#include "ScalarConverter.hpp"

/*
    El static_cast realiza conversiones de tipos verificando en la compilacion.
    Tiene seguridad de tipo pero no de valor y debe usarse cuando estámos seguros de que la conversión es válida.
    Esto quiere decir que el compilador realiza la conversión de tipos en tiempo de compilación,
    asegurandose de que cumplimos con las reglas de conversión de tipos, pero por ejemplo no tiene en cuenta
    si el valor de la variable es valido para el tipo al que se quiere convertir, como con el ejemplo la conversion
    de float a int, si el valor supera el rango de int, esto no se detecta en tiempo de compilación, es un error
    que el programador tiene que tener en cuenta, para que no se produzca un comportamiento indefinido en tiempo
    de ejecución.   
*/

int main(int argc, char **argv) {
    if (argc != 2 || !argv[1][0])
    {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return 1;
    }

    /*
    Comprobamos que no puede instanciarse un objeto de la clase
    ScalarConverter sc = new ScalarConverter();
    */
        
    try
    {   
        //std::string input = argv[1];
        std::string input(argv[1]);
        ScalarConverter::convert(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << std::endl;
    }
    return 0;
}
