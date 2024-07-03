#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/***************
* Constructors *
***************/

/* Debemos poner AForm en la lista de inicializacion o el compilador dara fallo
    En mi implementacion cualquier formulario copiado, estara sin firmar, lo mismo
    para la asignacion
*/
PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 72, 45), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
    std::cout << "Copy constructor called" << std::endl;
    this->_target = other._target;    
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
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

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();
	else if (!this->getSigned())
		throw PresidentialPardonForm::FormNotSigned();
    else
	    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}