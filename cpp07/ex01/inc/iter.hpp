/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/18 21:34:11 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_HPP
#define I_HPP

#include <iostream>
#include <stddef.h> //o <cstddef>, para size_t

template<typename T, typename F> //
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);  // Apply the function to each element
    }
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