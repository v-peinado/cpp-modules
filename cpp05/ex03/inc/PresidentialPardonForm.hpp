/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:09:19 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:09:20 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_HPP
#define P_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

/* Podremos acceder los miembros privados heredados, pero al no cambiarlos a protegidos
deberemos hacerlo mediante getter y setters*/

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &rhs);

#endif