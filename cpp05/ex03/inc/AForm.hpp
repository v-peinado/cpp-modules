/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:09:05 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:09:06 by vpeinado         ###   ########.fr       */
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

class AForm {
    private:
        std::string _name;
        bool _isSigned;
        int _requiredToSign;
        int _requiredToExec;
        std::string _target;
        AForm();
    public:
        AForm(std::string name, int toSign, int toExec);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &rhs);

        /*  Getters  */

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        std::string getTarget() const;

        /*  Setters  */

        void setName(std::string name);
        void setGradeExec(int grade);
        void setGradeSign(int grade);
        void setTarget(std::string target);

        /* Member function */

        void beSigned(Bureaucrat& Bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class FormNotSigned : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& outstream, const AForm &AForm);

#endif