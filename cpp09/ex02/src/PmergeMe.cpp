/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/27 22:17:12 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/******************************************************************************
* ------------------------------- CONSTRUCTORS ------------------------------ *
******************************************************************************/

PmergeMe::PmergeMe(std::string &str) : _str(str) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _str(other._str) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        _str = rhs._str;
    }
    return *this;
}

/*****************************************************************************
* -------------------------------- MEMBER FUNCTIONS -------------------------*
*****************************************************************************/

std::string PmergeMe::toString(unsigned int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void PmergeMe::init()
{
    this->alreadyPrinted = false;
    try 
    {
        parseValues(_str, this->_values_1);
        parseValues(_str,  this->_values_2);       
    } 
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return ;
    }
}

/*
    En esta funcion calcularemos la longitud que consideraremos adecuada para que insertion sort sea mas rapido que merge sort
    Para ello, calcularemos el threshold como el maximo entre 10 y el 10% del tamaño del vector,
    es decir si el tamaño del vector es 100, el threshold sera 10, si es 1000, el threshold sera 100, asi sucesivamente
    No ponemos el trheshold fijo porque si el vector es muy grande, se llamaria demasiadas veces a insertion sort.
*/
int PmergeMe::calculateThreshold(int threshold)
{
    return (std::max(10, threshold / 10));
}

