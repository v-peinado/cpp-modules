/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:06:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 13:40:45 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define HIGH 1
#define LOW 150

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredToSign;
        const int _requiredToExec;
        Form();
    public:
        Form(std::string name, int toSign, int toExec);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &rhs);

        /*  Getters  */

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        /* Member function */

        void beSigned(Bureaucrat& Bureaucrat);

        /* Exceptions */

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class FormIsSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

};

std::ostream& operator<<(std::ostream& outstream, const Form &Form);

#endif