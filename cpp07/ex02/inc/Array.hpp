/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:42:03 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 21:15:45 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>


template <typename T>
class Array {
    private:
        T *_array;
        //size_t _size;
        unsigned int _size;
    public:
        Array() : _array(new T[0]), _size(0) {
            //std::cout << "Default constructor called" << std::endl;
            if(!this->_array)
                throw std::bad_alloc();
        }
        Array(unsigned int n) : _array(new T[n]), _size(n) {
            //std::cout << "Parametric constructor called" << std::endl;
            if(!this->_array)
                throw std::bad_alloc();
        }
        ~Array() {
            //std::cout << "Destructor called" << std::endl;
            if(this->_array)
                delete [] _array;
        }
        Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
            //std::cout << "Copy constructor called" << std::endl;
            if(!this->_array)
                throw std::bad_alloc();
            for(unsigned int i = 0; i < _size; i++)
                this->_array[i] = other._array[i];
        }
        Array &operator=(const Array &rhs) {
            //std::cout << "Asignation operator called" << std::endl;
            if(this != &rhs)
            {
                if(this->_array)
                    delete [] this->_array;
                this->_array = new T[rhs._size];
                if(!this->_array)
                    throw std::bad_alloc();
                this->_size = rhs._size;
                for(unsigned int i = 0; i < _size; i++)
                    this->_array[i] = rhs._array[i];
            }
            return *this;
        }
        /*
            Prohibir la asignación preventiva significa que tu programa debe asignar 
            solo la cantidad exacta de memoria necesaria en ese momento y no más. 
            Esto asegura que no se reserve más memoria de la que se usa, evitando el desperdicio de recursos.
        */
        // Sobrecarga del operador [] para acceder a los elementos del array
        T &operator[](unsigned int index) {
            if(index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        
        unsigned int size() const {
            return _size;
        }
};

#endif