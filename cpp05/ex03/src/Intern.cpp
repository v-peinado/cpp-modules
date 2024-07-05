#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/***************
* Constructors *
***************/
Intern::Intern() {
    //std::cout << "Intern created" << std::endl;
}
Intern::~Intern() {
    //std::cout << "Intern has been destroyed" << std::endl;
}

Intern::Intern(const Intern &other) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/********************
* Operators overload *
********************/
Intern &Intern::operator=(const Intern &rhs) {
    //std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
        *this = rhs;
    return *this;
}

/*******************
* Member functions *
*******************/

AForm * Intern::makeForm(std::string name, std::string target) {
    int i = 0;
    std::string type[] = { "Presidential",
                         "Robotomy",
                         "Shrubbery"
                        };
    for(i = 0; i < 3; i++)
        if(name == type[i])
            break;
    switch (i)
    {
        case 0:
            return new RobotomyRequestForm(target);
        case 1:
            return new PresidentialPardonForm(target);
        case 2:
            return new ShrubberyCreationForm(target);            
        default:
            throw Intern::BadNameException();
    }
    return NULL;
}

/********************
* Virtual functions *
********************/

const char* Intern::BadNameException::what() const throw() {
    return "BadNameException: can't create form";
}