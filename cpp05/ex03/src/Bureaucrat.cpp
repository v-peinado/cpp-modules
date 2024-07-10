/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:09:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:09:43 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/***************
* Constructors *
***************/

Bureaucrat::Bureaucrat(std::string name, int lvl) : _name(name) {
    if(lvl > LOW)
        throw Bureaucrat::GradeTooLowException();
    else if(lvl < HIGH)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = lvl;
    //std::cout << "Bureaucrat " << _name << " has been created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    //std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/********************
* Operators overload *
********************/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    //std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &rhs) {
    outstream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return outstream;
}

/*******************
* Member functions *
*******************/

int Bureaucrat::getGrade() const {
    return this->_grade;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

void Bureaucrat::incrementGrade(int grades) {
    if(this->_grade - grades < HIGH)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade -= grades;
}

void Bureaucrat::decrementGrade(int grades) {
    if(this->_grade + grades > LOW)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade += grades;
}

void Bureaucrat::signForm(AForm &AForm) {
    if(AForm.getSigned())
        throw AForm::FormIsSignedException();
    else if(this->_grade > AForm.getGradeToSign())
        throw AForm::GradeTooLowException();
    else
        AForm.beSigned(*this); 
}

void Bureaucrat::executeForm(AForm const &AForm) {
    if(!AForm.getSigned())
        throw AForm::FormNotSigned();
    else if(this->_grade > AForm.getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        AForm.execute(*this);
    }  
}

/********************
* Virtual functions *
********************/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException: Grade too high, < 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException: Grade too low, > 150";
}