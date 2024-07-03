#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

/***************
* Constructors *
***************/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

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

std::ostream &operator<<(std::ostream &outstream, const ShrubberyCreationForm &rhs) {
    outstream << "Form: " << rhs.getName() << std::endl;
    outstream << "Grade requiered to sign: " << rhs.getGradeToSign() << std::endl;
    outstream << "Grade requiered to exec: " << rhs.getGradeToExec() << std::endl;
    outstream << "Target: " << rhs.getTarget() << std::endl;
    if(rhs.getSigned())
        outstream << "Form " << rhs.getName() << " SIGNED" << std::endl;
    else
        outstream << "Form " << rhs.getName() << " NOT SIGNED" << std::endl;
    return outstream;
}

const std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

/********************
* Virtual functions *
********************/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (!this->getSigned())
		throw ShrubberyCreationForm::FormNotSigned();
    else
	{
        std::ofstream out;
    	out.open((this->_target + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
        out << "     *\n"
            << "    ***\n"
            << "   *****\n"
            << "  *******\n"
            << " *********\n"
            << "    | |\n ";
        out.close();
    }
}