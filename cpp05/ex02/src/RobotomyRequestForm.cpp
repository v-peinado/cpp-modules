/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:08:31 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/10 14:22:20 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

/***************
* Constructors *
***************/

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 25, 5) {
        this->setTarget(target);
    }

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Debemos poner AForm en la lista de inicializacion o el compilador dara fallo
    En mi implementacion cualquier formulario copiado, estara sin firmar, lo mismo
    para la asignacion
*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
    std::cout << "Copy constructor called" << std::endl;
    this->setTarget(other.getTarget());    
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
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

std::ostream &operator<<(std::ostream &outstream, const RobotomyRequestForm &rhs) {
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

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLowException();
	else if (!this->getSigned())
		throw RobotomyRequestForm::FormNotSigned();
    else
    {
        std::srand(std::time(NULL));
        std::cout << this->getTarget() << " has been robotomized successfully 50% of the time" << std::endl;
        if(std::rand() % 2 == 0)
            std::cout << "ERROR... robotomy failed" << std::endl;
        else
            std::cout << this->getTarget() << " has been robotomized" << std::endl;
    }
	    
}