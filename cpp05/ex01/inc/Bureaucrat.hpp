#ifndef BURO_HPP
#define BURO_HPP

#define HIGH 1
#define LOW 150

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        std::string _name;
        int _grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string name, int lvl); 
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &rhs);

        /*  Getters  */

        int getGrade() const;
        std::string getName() const;

        /*   Member functions  */

        //friend std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &rhs);
        void incrementGrade(int grades);
        void decrementGrade(int grades);
        void signForm(Form &Form);

        /*  Exception classes  */

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &rhs);

#endif