/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:35:29 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/12 21:07:51 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_HPP
#define W_HPP

template <typename T>
void swap(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}

template <typename T>
T max(T &a, T &b) {
    if (a > b)
        return a;
    else
        return b;
}

template <typename T>
T min(T &a, T &b) {
    if (a < b)
        return a;
    else
        return b;
}

#endif