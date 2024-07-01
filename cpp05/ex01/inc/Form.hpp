#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

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

        const std::string getName() const;
        const bool getSigned() const;
        const int getGradeToSign() const;
        const int getGradeToSign() const;

        /* Member function */

        void beSigned(Bureaucrat& Bureaucrat);

        /* Exceptions */

        
};

std::ostream& operator<<(std::ostream& outstream, const Form &Form);

#endif