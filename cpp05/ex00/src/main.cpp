#include "Bureaucrat.hpp"

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
    
    
    
    return 0;
}