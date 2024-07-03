#ifndef FORM_HPP
#define FORM_HPP

#define HIGH 1
#define LOW 150

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string _name;
        bool _isSigned;
        int _requiredToSign;
        int _requiredToExec;
        AForm();
    public:
        AForm(std::string name, int toSign, int toExec);
        ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &rhs);

        /*  Getters  */

        const std::string getName() const;
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

std::ostream& operator<<(std::ostream& outstream, const AForm &AForm);

#endif