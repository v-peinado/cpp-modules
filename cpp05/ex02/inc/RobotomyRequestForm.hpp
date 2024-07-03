#ifndef R_HPP
#define R_HHP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

        void execute(Bureaucrat const & executor) const;
};

#endif