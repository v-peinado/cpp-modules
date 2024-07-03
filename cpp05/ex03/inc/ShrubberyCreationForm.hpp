#ifndef S_HPP
#define S_HHP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

        const std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstream, const ShrubberyCreationForm &rhs);

#endif