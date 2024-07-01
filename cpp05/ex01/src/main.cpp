#include "Bureaucrat.hpp"

/*
    Una excepcion es un mecanismo que permite manejar errores en tiempo de ejecución, 
    sin interrumpir el flujo normal del programa. Proporcionan una manera estructurada de
    gestionar errores y permiten separar el código de manejo de errores del código normal.
    Hay varios tipos de excepciones(derivadas de std::exception, ejemplo std::runtime_error), 
    pero en este caso se usan las excepciones de la libreria estandar std::exception
    y se personalizan para el caso de la clase Bureaucrat, creando dos clases hijas de std::exception.
    
    Dentro de estas excepciones se sobreescribe el metodo what() que hereda virtualmente de std::exception
    que devuelve un puntero a una cadena de caracteres que describe el error que se ha producido, y lo personalizamos.
    Las excepciones deben ser capturadas en un bloque try and catch, donde se intenta ejecutar el codigo que puede lanzar
    una excepcion y se captura en el bloque catch, donde se puede manejar el error.
    La idea es que todo codigo que pueda producir excepciones se ejecute dentro de un bloque try and catch.
    Si una excepcion no esta dentro de un bloque try and catch, se lanzara una excepcion no capturada y se llamara a std::terminate
    y se terminara el programa, posiblemnte con un volcado de memoria.
*/

int main(void) {
    std::cout << "CONSTRUCTOR" << std::endl;
    Bureaucrat a("Burocrata A", 5);
    std::cout << "===========" << std::endl;
    std::cout << "GETTERS" << std::endl;
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "Grade: " << a.getGrade() << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << "DECREMENT" << std::endl;
    a.decrementGrade(4);
    std::cout << "New grade: " << a.getGrade() << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << "PRINT WITH <<: " << std::endl;
    std::cout << a << std::endl;
    std::cout << "===========" << std::endl;

    /*
        Si no usamos un bloque try and catch para capturar las excepciones,
        se lanzara una excepcion pero no sera atrapada por lo que se llamara
        a std::terminate ,lo que resulta en la terminación inmediata del programa
        y un volcado de memoria

        Puedes provocarla intentando:
        a.decrementGrade(200);
    */

    try 
    {
        Bureaucrat b("Burocrata B", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("Burocrata C", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.decrementGrade(200);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        a.decrementGrade(200);
    }
    catch(...)
    {
        std::cerr << "Sin personalizar la excepcion" << std::endl;
    }


    return 0;
}