
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    std::cout << "===========================" << std::endl;
    std::cout << "Create forms and bureacrats" << std::endl;
    std::cout << "===========================" << std::endl;

    Bureaucrat a("(O_O)", 9);
    PresidentialPardonForm b("PPF_Target");
    RobotomyRequestForm c("RRF_Target");
    ShrubberyCreationForm d("SCF_Target");

    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Overload of the («) operator" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "       Form not signed      " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        b.execute(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "============================" << std::endl;
    std::cout << "       Low to exec          " << std::endl;
    std::cout << "============================" << std::endl;
    
    try
    {
        Bureaucrat x("(O_O)", 50);
        b.beSigned(x);
        b.execute(x);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "       Low to sign          " << std::endl;
    std::cout << "============================" << std::endl;
    
    try
    {
        c.beSigned(a);
        c.execute(a);
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
        Bureaucrat ert("(O_O)", 1);
        PresidentialPardonForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ok_form.execute(ert);
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
        Bureaucrat ert("(O_O)", 1);
        RobotomyRequestForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ok_form.execute(ert);
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
        Bureaucrat ert("(O_O)", 1);
        ShrubberyCreationForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ok_form.execute(ert);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}