#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

/***************
* Constructors *
***************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 25, 5), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Debemos poner AForm en la lista de inicializacion o el compilador dara fallo
    En mi implementacion cualquier formulario copiado, estara sin firmar, lo mismo
    para la asignacion
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
    std::cout << "Copy constructor called" << std::endl;
    this->_target = other._target;    
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->setName(rhs.getName());
        this->setGradeExec(rhs.getGradeToExec());
        this->setGradeSign(rhs.getGradeToSign());
        this->_target = rhs._target;
    }
    return *this;
}

/********************
* Virtual functions *
********************/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    int randomValue = std::rand();
	if (executor.getGrade() > this->getGradeToExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (!this->getSigned())
		throw ShrubberyCreationForm::FormNotSigned();
    else
    {
        std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
        if(randomValue % 2)
            std::cout << "ERROR... robotomy failed" << std::endl;
        else
            std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
    }
	    
}