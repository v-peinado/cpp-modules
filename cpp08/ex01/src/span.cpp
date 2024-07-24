/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:32:54 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/24 22:03:57 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

/******************************************************************************
* ------------------------------- CONSTRUCTORS ------------------------------ *
******************************************************************************/

Span::Span(unsigned int n) : _N(n)
{
    /*
        Si sabes de antemano cuántos elementos aproximadamente tendrá el vector,
        llamar a reserve puede mejorar el rendimiento al reducir la cantidad de 
        realocaciones de memoria que ocurren cuando el vector crece
    */
    _vector.reserve(n);
}

Span::Span(Span const &other)
{
    *this = other;
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _N = other._N;
        _vector = other._vector;
    }
    return *this;
}

Span::~Span() {}

/*****************************************************************************
* ------------------------------- MEMBER FUNCTIONS ------------------------- *
*****************************************************************************/

void Span::addNumber(int n)
{
    if (n < 0)
        throw std::runtime_error("Negative numbers are not allowed");
    if (_vector.size() < _N)
        _vector.push_back(n);
    else
        throw std::runtime_error("Span is full");
}

int Span::shortestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; it++)
    {
        if (*(it + 1) - *it < min)
            min = *(it + 1) - *it;
    }
    return min;
}

int Span::longestSpan()
{
    if (_vector.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

void Span::fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_vector.size() + std::distance(begin, end) > _N)
        throw std::runtime_error("Not enough space in span");
    _vector.insert(_vector.end(), begin, end);
}

void Span::fillVector()
{
    for (unsigned int i = 0; i < _N; i++)
        _vector.push_back(i);
}

