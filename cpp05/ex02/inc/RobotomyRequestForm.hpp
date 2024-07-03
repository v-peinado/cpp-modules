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

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstream, const RobotomyRequestForm &rhs);

#endif