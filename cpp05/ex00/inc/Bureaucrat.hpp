/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:06:09 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/09 18:06:17 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BURO_HPP
#define BURO_HPP

#define HIGH 1
#define LOW 150

#include <iostream>
#include <string>
#include <exception>

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
        /*Al retornar valores y no punteros o referencias es innecesario poner const int o const std::string*/
        int getGrade() const;
        std::string getName() const;

        /*   Member functions  */

        //friend std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &rhs);
        void incrementGrade(int grades);
        void decrementGrade(int grades);

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