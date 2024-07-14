/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:06:05 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/14 22:30:36 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>


int main(void) {
    
    std::cout << "Se crea un array de 5 elementos" << std::endl;
    Array<int> arr(5);
    std::cout << "Se asignan valores aleatorios a los elementos" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = rand();
    std::cout << "Se imprime el array" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    std::cout << "Se crea otro array de 5 elementos" << std::endl;
    Array<int> arr2(5);
    std::cout << "Se asignan valores aleatorios a los elementos" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = rand();
    std::cout << "Se imprime el array" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << std::endl;
    std::cout << "Se copia el primer array en el segundo" << std::endl;
    arr2 = arr;
    std::cout << "Se imprime el segundo array" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << std::endl;
    std::cout << "Se modifica el segundo array" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = 2;
    std::cout << "Se imprime el primer array" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    std::cout << "Se imprime el segundo array para ver si son diferentes" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << std::endl;
    std::cout << "Probamos crear un array vacio" << std::endl;
    Array<int> arr3;
    std::cout << "Se imprime el array vacio, no se imprime nada" << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << std::endl;
    std::cout << "Asignamos los valores de arr2 al elemento vacio" << std::endl;
    arr3 = arr2;
    std::cout << "Se imprime el arr3" << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << std::endl;
    std::cout << "Se intenta acceder a un elemento fuera de rango" << std::endl;
    try {
        arr2[10] = 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Se intenta acceder a un elemento fuera de rango" << std::endl;
    try {
        arr2[-1] = 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}


/*
    El main de 42 es bastante inclompleto, por lo que creamos uno nuevo
*/
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     std::srand(std::time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         std::cout << "Se prueba index -2" << std::endl;
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         /*
//         se prueba index 750, que es el maximo y lanzara excepcion, porque el array es de 750
//         por lo que el maximo index es 749
//         */
//         std::cout << "Se prueba index 750" << std::endl;
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }