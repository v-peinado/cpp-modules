/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:07:03 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 13:02:26 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/***************
* Constructors *
***************/

Form::Form(std::string name, int toSign, int toExec) : _name(name), _isSigned(false), _requiredToSign(toSign), _requiredToExec(toExec) {
    if(toSign < HIGH || toExec < HIGH)
        throw Form::GradeTooHighException();
    if(toSign > LOW || toExec > LOW)
        throw Form::GradeTooLowException();
    std::cout << "Form " << this->_name << " has been created" << std::endl;
}

Form::~Form() {
    std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _requiredToSign(other._requiredToSign), _requiredToExec(other._requiredToExec) {
    std::cout << "Copy constructor called" << std::endl;  
}

/********************
* Operators overload *
********************/

Form &Form::operator=(const Form &rhs) {
    std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outstream, const Form &rhs) {
    outstream << "Form: " << rhs.getName() << std::endl;
    outstream << "Grade requiered to sign: " << rhs.getGradeToSign() << std::endl;
    outstream << "Grade requiered to exec: " << rhs.getGradeToExec() << std::endl;
    if(rhs.getSigned())
        outstream << "Form " << rhs.getName() << " SIGNED" << std::endl;
    else
        outstream << "Form " << rhs.getName() << " NOT SIGNED" << std::endl;
    return outstream;
}

/*******************
* Member functions *
*******************/

std::string Form::getName() const {
    return this->_name;
}

int Form::getGradeToSign() const {
    return this->_requiredToSign;
}

int Form::getGradeToExec() const {
    return this->_requiredToExec;
}

bool Form::getSigned() const {
    return this->_isSigned;
}

void Form::beSigned(Bureaucrat &Bureaucrat) {
    if(this->_isSigned)
        throw Form::FormIsSignedException();
    else if(Bureaucrat.getGrade() > this->_requiredToSign)
        throw Form::GradeTooLowException();
    else
    {
        std::cout << "Form confirmation:" << std::endl;
        std::cout << "The bureaucrat " << Bureaucrat.getName();
        std::cout << " sign Form " << getName() << std::endl;
        this->_isSigned = true;
    }
}

/********************
* Virtual functions *
********************/

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Form::FormIsSignedException::what() const throw() {
    return "Form already signed";
}

