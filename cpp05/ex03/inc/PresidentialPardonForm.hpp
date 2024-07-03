#ifndef P_HPP
#define P_HHP

#include <iostream>
#include <string>
#include "AForm.hpp"

/* Podremos acceder los miembros privados heredados, pero al no cambiarlos a protegidos
deberemos hacerlo mediante getter y setters*/

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &rhs);

#endif