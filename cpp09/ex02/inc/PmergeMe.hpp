/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:08 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/25 00:40:26 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <cstdio>

class PmergeMe
{
    private:
        std::deque<unsigned int> _values_1;
        std::vector<unsigned int> _values_2;
        std::list<unsigned int> _values_3;
        std::string _str;

        /*****************
        *   TEMPLATES    *
        *****************/

        //Añadir un método privado que se llame iter_print que reciba el STL container que se le pase y que imprima los valores que contiene.
        template <typename STL>
        void iter_print(STL &container)
        {
            for (typename STL::iterator it = container.begin(); it != container.end(); it++)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        
        template <typename STL>
        bool is_sort(STL &container)
        {
            for (typename STL::iterator it = container.begin(); it != container.end(); it++)
            {
                if (*it > *(it + 1))
                    return false;
            }
            return true;
        }

        template <typename STL>
        void parse_values(std::string &str, STL &container) {
            std::stringstream ss(str);
            std::string token;
            char delimiter = ' ';

            // Iterar sobre los tokens separados por espacios
            while (std::getline(ss, token, delimiter)) {
                std::stringstream tokenStream(token);
                int value;

                // Comprobar si el token es un número entero válido
                if (!(tokenStream >> value) || value < 0 || tokenStream.peek() != EOF) {
                    throw std::invalid_argument("Invalid number: " + token);
                }
                // Añadir el número a las estructuras de datos
                container.push_back(value);
            }
        }
        std::string to_string(unsigned int value);
        PmergeMe();
    public:
        PmergeMe(std::string &str);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &rhs);
        
        void init();       
};

#endif