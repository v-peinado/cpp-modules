/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:08:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:08:11 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/***************
* Constructors *
***************/

AForm::AForm(std::string name, int toSign, int toExec) : _name(name), _isSigned(false) {
    if(toSign < HIGH || toExec < HIGH)
        throw AForm::GradeTooHighException();
    if(toSign > LOW || toExec > LOW)
        throw AForm::GradeTooLowException();
    this->_requiredToSign = toSign;
    this->_requiredToExec = toExec;
    //std::cout << "AForm " << this->_name << " has been created" << std::endl;
}

AForm::~AForm() {
    //std::cout << "AForm " << this->_name << " has been destroyed" << std::endl;
}

AForm::AForm(const AForm &other) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/********************
* Operators overload *
********************/

AForm &AForm::operator=(const AForm &rhs) {
    //std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->_name = rhs._name;
        this->_isSigned = rhs._isSigned;
        this->_requiredToExec = rhs._requiredToExec;
        this->_requiredToSign = rhs._requiredToSign;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outstream, const AForm &rhs) {
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

std::string AForm::getName() const {
    return this->_name;
}

int AForm::getGradeToSign() const {
    return this->_requiredToSign;
}

int AForm::getGradeToExec() const {
    return this->_requiredToExec;
}

bool AForm::getSigned() const {
    return this->_isSigned;
}

std::string AForm::getTarget() const {
    return this->_target;
}

void AForm::beSigned(Bureaucrat &Bureaucrat) {
    if(this->_isSigned)
        throw AForm::FormIsSignedException();
    else if(Bureaucrat.getGrade() > this->_requiredToSign)
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "The bureaucrat " << Bureaucrat.getName();
        std::cout << " sign Form " << getName() << std::endl;
        this->_isSigned = true;
    }
}

void AForm::setName(std::string name) {
    this->_name = name;
}
void AForm::setGradeExec(int grade){
    this->_requiredToExec = grade;
}

void AForm::setGradeSign(int grade){
    this->_requiredToSign = grade;
}

void AForm::setTarget(std::string target) {
    this->_target = target;
}

/********************
* Virtual functions *
********************/

const char* AForm::GradeTooHighException::what() const throw() {
    return "GradeTooHighException: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "GradeTooLowException: Grade too low";
}

const char* AForm::FormIsSignedException::what() const throw() {
    return "FormIsSignedException: Form already signed";
}

const char* AForm::FormNotSigned::what() const throw() {
    return "FormNotSigned: Form not signed";
}
