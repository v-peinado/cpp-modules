/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:17:53 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/22 21:54:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include  <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<double> _values;
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