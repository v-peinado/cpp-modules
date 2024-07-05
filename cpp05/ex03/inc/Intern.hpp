#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &rhs);

        AForm * makeForm(std::string name, std::string target);

        class BadNameException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif