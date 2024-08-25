/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:14 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/25 22:06:39 by vpeinado         ###   ########.fr       */
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

std::string PmergeMe::to_string(unsigned int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void PmergeMe::init()
{
    try 
    {
        parse_values(_str, this->_values_1);
        parse_values(_str,  this->_values_2);
        //parse_values(_str,  this->_values_3);
               
    } 
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return ;
    }
}
    int PmergeMe::calculateThreshold(int threshold)
    {
        return (std::max(10, threshold / 10));
    }
