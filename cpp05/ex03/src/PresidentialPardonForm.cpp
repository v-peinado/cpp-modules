/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:10:01 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:10:02 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    : AForm("PresidentialPardonForm", 72, 45) {
        this->setTarget(target);
    }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
    std::cout << "Copy constructor called" << std::endl;
    this->setTarget(other.getTarget());    
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->setName(rhs.getName());
        this->setGradeExec(rhs.getGradeToExec());
        this->setGradeSign(rhs.getGradeToSign());
        this->setTarget(rhs.getTarget());
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &rhs) {
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
	    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}