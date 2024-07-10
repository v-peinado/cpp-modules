/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:06:58 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:06:59 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
    std::cout << "Bureaucrat " << _name << " has been created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/********************
* Operators overload *
********************/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    std::cout << "Asignation operator called" << std::endl;
    if(this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
}
/*
    La clase ostream, permite la sobrecarga del operador  <<, modificando el flujo de salida
    de tal manera que cada vez que usemos << con cualquier objeto Bureaucrat obtendremos una salida personalizada
    La sobrecarga del operador de inserción (<<) para std::ostream no se puede declarar como un miembro de una clase porque 
    el primer operando de la sobrecarga debe ser un std::ostream,
    y en C++, el primer operando de un operador sobrecargado siempre es el objeto de la 
    clase si el operador se define como un miembro de la clase.

    Si podriamos declararla como funcion amiga dentro de la clase y podria acceder a miembros privados y protegidos,
    pudiendo prescindir de los getters.
*/
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

void Bureaucrat::signForm(Form &Form) {
    if(Form.getSigned())
        throw Form::FormIsSignedException();
    else if(this->_grade > Form.getGradeToSign())
        throw Form::GradeTooLowException();
    else
    {
        Form.beSigned(*this);
    }
    
}

/********************
* Virtual functions *
********************/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high, < 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low, > 150";
}