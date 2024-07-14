/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:07:58 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:07:59 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_HPP
#define R_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &outstream, const RobotomyRequestForm &rhs);

#endif