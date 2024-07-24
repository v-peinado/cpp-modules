/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:32:57 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/24 14:22:37 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vector;
        Span();
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);  
};

#endif