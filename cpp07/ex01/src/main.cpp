/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:47 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 19:23:48 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main () {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    //No es lo correcto, pero para el ejemplo sirve, simplemente para mostrar que funciona con cualquier tipo de dato
    const char* strsArray[] = {"hola", "que", "tal", "estas", "?"};

    std::cout << "******************" << std::endl;
    std::cout << "*    INT ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(intArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "After addOne:" << std::endl;
    iter(intArray, 5, addOne);
    iter(intArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "After subOne:" << std::endl;
    iter(intArray, 5, subOne);
    iter(intArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << "*   CHAR ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(charArray, 5, print);

    std::cout << std::endl;
    std::cout << "After toUpper:" << std::endl;
    iter(charArray, 5, toUpper);
    iter(charArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << "*  FLOAT ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(floatArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "After addOne:" << std::endl;
    iter(floatArray, 5, addOne);
    iter(floatArray, 5, print);
    
    std::cout << std::endl;
    std::cout << "After subOne:" << std::endl;
    iter(floatArray, 5, subOne);
    iter(floatArray, 5, print);
    std::cout << std::endl;

    std::cout << "******************" << std::endl;
    std::cout << "*  STRS ARRAY    *" << std::endl;
    std::cout << "******************" << std::endl;

    std::cout << "Original array:" << std::endl;
    iter(strsArray, 5, print);

    return 0;
}