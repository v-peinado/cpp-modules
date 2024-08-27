/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:17:53 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/22 22:36:29 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include  <iostream>
#include <stack>

class RPN
{
    private:
        //Alternando double a int, podemos hacer que la calculadora RPN funcione con números enteros o decimales.
        //std::stack<double> _values;
        std::stack<int> _values;
        std::string _str;
        RPN();
    public:
        RPN(std::string &str);
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &rhs);
        void calculate();
};
#endif