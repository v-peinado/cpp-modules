/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:08:22 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 14:08:54 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
    Crearemos clases derivadas de AForm, que serán los formularios que se pueden firmar y ejecutar.
    Estos formularios tendrán un objetivo, que será el objetivo de la acción que se realizará al ejecutar el formulario.
    Cada formulario tendrá un método execute que realizará la acción que se espera de él.
    El subject deja claro que las propiedades que se heredan deben heredarse en privado, en la herencia publica
    se heredan los metodos publicos y protegidos, pero no los privados, por lo que deberemos acceder a ellos mediante
    metodos get y set, de la clase base, recordando que cada vez que se instancia una clase derivada, se instancia
    tambien la clase base.

*/

int main(void) {
    std::cout << "===========================" << std::endl;
    std::cout << "Create forms and bureacrats" << std::endl;
    std::cout << "===========================" << std::endl;

    Bureaucrat a("(O_O)", 9);
    PresidentialPardonForm b("PPF_Target");
    RobotomyRequestForm c("RRF_Target");
    ShrubberyCreationForm d("SCF_Target");

    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Overload of the («) operator" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "       Form not signed      " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        b.execute(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "============================" << std::endl;
    std::cout << "       Low to exec          " << std::endl;
    std::cout << "============================" << std::endl;
    
    try
    {
        Bureaucrat x("(O_O)", 50);
        b.beSigned(x);
        //b.execute(x);
        x.executeForm(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "       Low to sign          " << std::endl;
    std::cout << "============================" << std::endl;
    
    try
    {
        Bureaucrat y("(O_O)", 150);
        c.beSigned(y);
        c.execute(a);
        y.executeForm(c);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "         PPF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        Bureaucrat ert("(O_O)", 1);
        PresidentialPardonForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ok_form.execute(ert);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }


    std::cout << "============================" << std::endl;
    std::cout << "         RRF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        Bureaucrat ert("(O_O)", 1);
        RobotomyRequestForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ok_form.execute(ert);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    /*
        En las siguientes pruebas, se usara la funcion de executeForm, que es un metodo de Bureaucrat
    */
    std::cout << "============================" << std::endl;
    std::cout << "         SCF ALL OK         " << std::endl;
    std::cout << "============================" << std::endl;

    try
    {
        Bureaucrat ert("(O_O)", 1);
        ShrubberyCreationForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ert.executeForm(ok_form);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "      BURO exec FORM        " << std::endl;
    std::cout << "============================" << std::endl;
    try
    {
        Bureaucrat ert("(O_O)", 1);
        PresidentialPardonForm ok_form("PPF_Target");
        ok_form.beSigned(ert);
        ert.executeForm(ok_form);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
    

    return 0;
}