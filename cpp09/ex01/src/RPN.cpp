/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/26 13:54:25 by vpeinado         ###   ########.fr       */
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
bool isNumber(const std::string& token) 
{
    if (token.empty()) 
        return false;
    // Verificamos si el token es un número decimal, usando el parseo de stringstream
    std::stringstream ss(token);
    double d;
    char c;
    // Si la conversion a double falla o la conversión a char no falla, entonces no es un número
    if (!(ss >> d) || (ss >> c)) 
    {
        return false;
    }
    return true;
}

// Función para convertir un token en un número decimal
double stringToDouble(const std::string& token) 
{
    double value;
    std::stringstream ss(token);
    ss >> value;
    if (ss.fail()) 
    {
        throw std::invalid_argument("Invalid number: " + token);
    }
    return value;
}

void RPN::calculate() 
{
    // Creamos un stringstream para leer el string de la expresión RPN
    std::stringstream ss(this->_str);
    std::string token;
   /*
    El operador de extracción >> se utiliza para leer datos desde un flujo (como std::cin o std::stringstream) y almacenarlos en una variable.
    Este operador, cuando se usa con std::string, lee automáticamente el siguiente "token" de texto, que por defecto es una secuencia de caracteres no separada por espacios.
    El flujo de datos se detiene en el primer espacio en blanco que encuentra. Tokenizando la cadena de entrada, podemos leer cada número y operador por separado.
   */
    while (ss >> token) 
    {
        // Si el token es un número, lo agregamos a la pila
        if (isNumber(token)) 
        {
            double value = stringToDouble(token);
            if (value > 9 || value < -9) 
            {
                throw std::invalid_argument("Number out of range: " + token); //suponemos que los números son de 0 a 9, pero funciona con cualquier número
            }
            this->_values.push(value);
        } 
        else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos) 
        {
            // Si el token es un operador, aplicamos la operación a los dos valores superiores de la pila
            if (this->_values.size() < 2) 
            {
                // Si no hay suficientes valores para el operador, lanzamos una excepción
                throw std::runtime_error("Not enough values for operator: " + token);
            }
            // Obtenemos los dos valores superiores de la pila, almaacenamos en temporales y los eliminamos de la pila
            //stack = [1, 2], si nos hemos encontrado con un operador, los guardamos en a y b y los eliminamos de la pila
            // luego hacemos la operación y guardamos el resultado en la pila, seguimos avanzando en el string y repitiendo el proceso
            double b = this->_values.top(); //top() devuelve el valor del elemento superior de la pila
            this->_values.pop(); //pop() elimina el elemento superior de la pila
            double a = this->_values.top();
            this->_values.pop();
            // Aplicamos la operación y almacenamos el resultado en la pila
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
    // Al final de la expresión, si la pila no contiene exactamente un valor, la expresión es inválida
    if (this->_values.size() != 1) {
        throw std::runtime_error("Invalid RPN expression");
    }
    std::cout << this->_values.top() << std::endl;
}


