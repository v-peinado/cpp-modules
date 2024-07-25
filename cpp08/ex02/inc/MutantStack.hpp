/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:19 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/25 21:43:40 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_HPP
#define M_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <iostream>
/*
    En C++, los contenedores de la Biblioteca Estándar (STL) como std::stack, std::queue, etc., 
    se construyen sobre otros contenedores de datos llamados contenedores subyacentes. 
    Estos contenedores subyacentes son instancias de otros contenedores STL,
     como std::vector, std::deque o std::list, que proporcionan la implementación real de almacenamiento y manipulación de datos.
    MutantStack hereda de std::stack para proporcionar iteradores, 
    lo que no está disponible en std::stack por defecto.
    std::stack usa std::deque o std::vector como su contenedor subyacente, que sí es iterable.
    Un contenedor subyacente es un contenedor que se utiliza para almacenar los elementos de otro contenedor.
    Esto se hace para proporcionar una interfaz más simple y fácil de usar para el usuario, 
    ya que el contenedor subyacente se encarga de la gestión de la memoria y la manipulación de los elementos.
    es posible acceder al contenedor subyacente para proporcionar funcionalidades adicionales. 
    Aquí es donde el contenedor subyacente (std::deque o std::vector en el caso de std::stack) 
    se expone para proporcionar características adicionales, como iteradores.
*/

template <typename T> 
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &src) : std::stack<T>(src) {}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack const &rhs)
        {
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return *this;
        }
        /*
            Implementaremos los iteradores begin, end, rbegin y rend para poder recorrer el stack
        */
        //typedef es una forma de definir un alias para el tipo de iterador reverse_iterator del contenedor subyacente de std::stack<T>
        //cada vez que por ejemplo se llame a reverse_iterator se llamará a typename std::stack<T>::container_type::reverse_iterator
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::iterator iterator; 
        
        iterator begin() { 
            return std::stack<T>::c.begin(); 
            }
        iterator end() { 
            return std::stack<T>::c.end(); 
            }
        reverse_iterator rbegin() { 
            return std::stack<T>::c.rbegin(); 
            }
        reverse_iterator rend() {
            return std::stack<T>::c.rend(); 
            }  
        /*
            Implementaremos tambien iteradores constantes para que el usuario no pueda modificar el contenido del stack
        */
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        
        const_iterator cbegin() const { 
            return std::stack<T>::c.cbegin(); 
            }
        const_iterator cend() const {
            return std::stack<T>::c.cend(); 
            }
        const_reverse_iterator crbegin() const {
            return std::stack<T>::c.crbegin(); 
            }
        const_reverse_iterator crend() const {
            return std::stack<T>::c.crend(); 
            }            
};


#endif