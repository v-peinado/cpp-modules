/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:32:50 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/24 20:18:07 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "========================" << std::endl
              << "  Test add more than N  " << std::endl
              << "========================" << std::endl;
    try
    {
        sp.addNumber(42); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::endl(std::cout);
    std::cout << "========================" << std::endl
              << "  Test negative         " << std::endl
              << "========================" << std::endl;
    try
    {
        sp.addNumber(-42); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::endl(std::cout);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::endl(std::cout);

    std::cout << "========================" << std::endl
              << "Test with 10000 elements  " << std::endl
              << "========================" << std::endl;
    // Test with 10000 elements
    //usaremos las dos funciones fillVector
    Span sp2 = Span(10000);
    sp2.fillVector();

    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

    Span sp3 = Span(10000);
    std::vector<int> vec;
    vec.reserve(10000);
    
    for (int i = 0; i < 10000; i++)
        vec.push_back(i);
    sp3.fillVector(vec.begin(), vec.end());
    
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    std::endl(std::cout);
    std::cout << "========================" << std::endl
              << "Test with 10001 elements  " << std::endl
              << "    range exception    " << std::endl
              << "========================" << std::endl;

    Span sp4 = Span(10000);
    std::vector<int> vec2;
    vec2.reserve(10001);
    for (int i = 0; i < 10001; i++)
        vec2.push_back(i);
    try
    {
        sp4.fillVector(vec2.begin(), vec2.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
     
    return 0;
}