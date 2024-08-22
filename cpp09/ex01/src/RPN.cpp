/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/22 21:52:57 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

/******************************************************************************
* ------------------------------- CONSTRUCTORS ------------------------------ *
******************************************************************************/

RPN::RPN(std::string &str) : _str(str) {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _str(other._str) {}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
        _str = rhs._str;
    return *this;
}

/******************************************************************************
* -------------------------------- MEMBER FUNCTIONS ------------------------- *
******************************************************************************/

// Función para verificar si un token es un número decimal
bool isNumber(const std::string& token) {
    if (token.empty()) 
        return false;
    
    std::stringstream ss(token);
    double d;
    char c;
    if (!(ss >> d) || (ss >> c)) {
        return false;
    }
    return true;
}

// Función para convertir un token en un número decimal
double stringToDouble(const std::string& token) {
    double value;
    std::stringstream ss(token);
    ss >> value;
    if (ss.fail()) {
        throw std::invalid_argument("Invalid number: " + token);
    }
    return value;
}

void RPN::calculate() {
    std::stringstream ss(this->_str);
    std::string token;

    while (ss >> token) {
        if (isNumber(token)) {
            double value = stringToDouble(token);
            this->_values.push(value);
        } else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos) {
            if (this->_values.size() < 2) {
                throw std::runtime_error("Not enough values for operator: " + token);
            }
            double b = this->_values.top();
            this->_values.pop();
            double a = this->_values.top();
            this->_values.pop();

            char op = token[0];
            switch (op) {
                case '+':
                    this->_values.push(a + b);
                    break;
                case '-':
                    this->_values.push(a - b);
                    break;
                case '*':
                    this->_values.push(a * b);
                    break;
                case '/':
                    if (b == 0.0) {
                        throw std::runtime_error("Division by zero");
                    }
                    this->_values.push(a / b);
                    break;
                default:
                    throw std::invalid_argument("Unknown operator: " + token);
            }
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }

    if (this->_values.size() != 1) {
        throw std::runtime_error("Invalid RPN expression");
    }
    std::cout << this->_values.top() << std::endl;
}


