
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
    Intern RandomIntern;
    std::cout << "===========================" << std::endl;
    std::cout << "      Bad name exception   " << std::endl;
    std::cout << "===========================" << std::endl;

    try
    {
        AForm* rrf;
        rrf = RandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;            
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }  

    std::cout << "============================" << std::endl;
    std::cout << "         PPF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        AForm* ppf;
        ppf = RandomIntern.makeForm("Presidential", "Bender"); 
        Bureaucrat ert("(O_O)", 1);
        ppf->beSigned(ert);
        ppf->execute(ert);
        delete ppf; 
        std::cout << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }


    std::cout << "============================" << std::endl;
    std::cout << "         RRF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        AForm* rrf;
        rrf = RandomIntern.makeForm("Robotomy", "Bender"); 
        Bureaucrat ert("(O_O)", 1);
        rrf->beSigned(ert);
        rrf->execute(ert);
        delete rrf; 
        std::cout << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "         SCF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        AForm* scf;
        scf = RandomIntern.makeForm("Shrubbery", "Bender"); 
        Bureaucrat ert("(O_O)", 1);
        scf->beSigned(ert);
        scf->execute(ert);
        delete scf; 
        std::cout << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}