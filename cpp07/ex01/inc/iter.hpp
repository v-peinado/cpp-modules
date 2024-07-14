/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 19:13:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_HPP
#define I_HPP

#include <iostream>
#include <stddef.h> //size_t

template <typename T>
void iter(T *array, size_t size, void (*f)(T&)) {
    for (size_t i = 0; i < size; i++) {
        f(array[i]);
    }
}

template <typename T>
void print(T &elem) {
    std::cout << elem << std::endl;
}

template <typename T>
void addOne(T &elem) {
    elem++;
}

template <typename T>
void subOne(T &elem) {
    elem--;
}

template <typename T>
void toUpper(T &elem) {
    if (elem >= 'a' && elem <= 'z')
        elem -= 32;
}

#endif