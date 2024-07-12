/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:06:09 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/12 21:20:39 by vpeinado         ###   ########.fr       */
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
        /*Al retornar valores y no punteros o referencias es innecesario poner const int o const std::string
            Retornar solo valor es mas ineficiente ya que al ser una copia Requiere una copia completa del objeto,
            lo que puede ser innecesario si solo se necesita acceder a la información, aunque C++ realiza optimizaciones
            como RVO(Return Value Optimization) que pueden minimizar el coste de devolver objetos por valor,
            aunque esto no aplica a todos los casos y compilers.
            Por otra parte devolver referencia podria ser menos seguro, por lo quees recomendable devolver una referencia
            constante (const&) si deseas eficiencia sin comprometer la seguridad.
            
        */
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