/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:07:10 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 13:45:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
    std::cout << "===========================" << std::endl;
    std::cout << "Create forms and bureacrats" << std::endl;
    std::cout << "===========================" << std::endl;
    Form a("A", 10, 10);
    Form c("C", 10, 10);
    Form x("X", 1, 1);
    Bureaucrat b("(O_O)", 9);
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Overload of the («) operator" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "     Form low exception    " << std::endl;
    std::cout << "===========================" << std::endl;

    try
    {
        Form error_1("TooLowForm", 160, 160);
        std::cout << error_1 << std::endl; 
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "===========================" << std::endl;
    std::cout << "     Form High exception    " << std::endl;
    std::cout << "===========================" << std::endl;

    try
    {
        Form error_2("TooHighForm", 0, 0);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    /* C++98 el manejo de excepciones no permite capturar 
        múltiples excepciones de manera directa como en 
        versiones más modernas de C++*/

    std::cout << "===========================" << std::endl;
    std::cout << "   Low and High exception  " << std::endl;
    std::cout << "===========================" << std::endl;

    try
    {
        Form error_3("AllBad", 200, 0);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }
 
    std::cout << "===========================" << std::endl;
    std::cout << "    Form Already signed    " << std::endl;
    std::cout << "===========================" << std::endl;
    
    a.beSigned(b); //a sera firmado una vez por b
    std::cout << std::endl;

    try
    {
        a.beSigned(b);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    c.beSigned(b); //c sera firmado una vez por b, para que luego b vuelva a intentar firmarlo
    std::cout << std::endl;

    try
    {
        b.signForm(c);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "===========================" << std::endl;
    std::cout << "    Grade too low to sign  " << std::endl;
    std::cout << "===========================" << std::endl;

    try
    {
        b.signForm(x);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error in Form: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}