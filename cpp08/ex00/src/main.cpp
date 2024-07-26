/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:40:51 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/26 18:10:56 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stdint.h>

/*
    STL (Standard Template Library) es una biblioteca de plantillas de C++ que proporciona estructuras de datos y algoritmos comunes.
    La STL se compone de varios componentes, como contenedores, iteradores, algoritmos, funciones y adaptadores.
    Los contenedores son estructuras de datos que almacenan elementos en una secuencia ordenada.
    Los iteradores son objetos que proporcionan una interfaz estandarizada para recorrer y operar sobre elementos en contenedores.
    Los algoritmos son funciones que realizan operaciones en los elementos de los contenedores.
*/


int main()
{
    std::cout << "*************************" << std::endl;
    std::cout << "Testing with vector<int>:" << std::endl;
    std::cout << "*************************" << std::endl;
        /*
        Un vector es un contenedor que almacena elementos del mismo tipo en una secuencia ordenada.
        Los elementos se almacenan en posiciones contiguas de memoria, lo que permite un acceso rápido a los elementos.
        Los vectores son similares a los arrays en C, pero tienen algunas diferencias importantes:
        - Los vectores son objetos, mientras que los arrays son punteros.
        - Los vectores tienen un tamaño dinámico, mientras que los arrays tienen un tamaño fijo.
        - Los vectores proporcionan funciones miembro para acceder y manipular los elementos, mientras que los arrays no.
        Tambien existe std::array, que es un contenedor de tamaño fijo que almacena elementos del mismo tipo en una secuencia ordenada.
    */
   
    //std::vector<int> vec = {1, 2, 3, 4, 5}; ESTA FORMA ESTA PROHIBIDA EN C++98
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Searching good value in vector:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Searching bad value in vector:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Print address of vector elements: " << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << &(*it) << " ";
    std::endl(std::cout);

    std::cout << "Print address of vector elements after cast to uintptr_t: " << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << reinterpret_cast<uintptr_t>(&(*it)) << " ";
    std::endl(std::cout);

    std::cout << "***********************" << std::endl;
    std::cout << "Testing with list<int>:" << std::endl;
    std::cout << "***********************" << std::endl;
    /*
        Una lista es un contenedor que almacena elementos del mismo tipo en una secuencia ordenada.
        Los elementos se almacenan en nodos enlazados, lo que permite un acceso rápido a los elementos.
        Las listas son similares a los vectores en C++, pero tienen algunas diferencias importantes:
        - Las listas son más eficientes para insertar y eliminar elementos en cualquier posición, mientras que los vectores son más eficientes para acceder a los elementos.
        - No se puede acceder a los elementos de una lista por índice, es necesario recorrer la lista desde el principio o desde el final.
    */
   
    //std::list<int> lst = {1, 2, 3, 4, 5}; ESTA FORMA ESTA PROHIBIDA EN C++98
    //Esta vez usaremos el constructor que recibe el rango de elementos a insertar, primer elemento arr, ultimo elemento arr + sizeof(arr) / sizeof(int)
    //sizeof(arr) / sizeof(int) nos da el tamaño del array arr, pero usaremos 5 directamente
    
    int arr[] = {1, 2, 3, 4, 5};
    //std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int> lst(arr, arr + 5);
 
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Searching good value in list:" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Searching bad value in list:" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Print address of list elements: " << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << &(*it) << " ";
    std::endl(std::cout);

    std::cout << "Print address of list elements after cast to uintptr_t: " << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << reinterpret_cast<uintptr_t>(&(*it)) << " ";
    std::endl(std::cout);

    std::cout << "*************************" << std::endl;
    std::cout << "Testing with deque<int>:" << std::endl;
    std::cout << "*************************" << std::endl;
    /*
        A diferencia de queue(FIFO) y que no sostienen iteradores, deque no es una cola, sino una doble cola, es decir, 
        una cola que permite inserciones y eliminaciones eficientes en ambos extremos.
        Un std::deque no garantiza que sus elementos estén en una sola región de memoria continua. 
        En su lugar, utiliza múltiples bloques de memoria para almacenar los datos. 
        Esto permite inserciones y eliminaciones eficientes en ambos extremos, 
        pero puede implicar que los datos no estén contiguos en la memoria, lo que puede afectar al rendimiento al acceder a los elementos.
        Al igual que los vectores, proporciona acceso mediante indices.
        Los deques son similares a los vectores en C++, pero tienen algunas diferencias importantes:
        - Los deques proporcionan funciones miembro para insertar y eliminar elementos en cualquier posición, mientras que los vectores no.
        - Los deques son más eficientes para insertar y eliminar elementos en cualquier posición, mientras que los vectores son más eficientes para acceder a los elementos.
    */
    std::deque<int> deq;
    for (int i = 1; i <= 5; i++)
        deq.push_back(i);
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Searching good value in deque:" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Searching bad value in deque:" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, 42);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Print address of deque elements: " << std::endl;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << &(*it) << " ";
    std::endl(std::cout);

    std::cout << "Print address of deque elements after cast to uintptr_t: " << std::endl;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << reinterpret_cast<uintptr_t>(&(*it)) << " ";
    std::endl(std::cout);
    
    /*
        A continuacion se muestra un ejemplo de como se comporta la función con un contenedor que no contiene elementos.
    */
    std::cout << "*************************" << std::endl;
    std::cout << "Testing with empty vector<int>:" << std::endl;
    std::cout << "*************************" << std::endl;
    std::vector<int> empty_vec;
    std::cout << "Empty vector: ";
    for (std::vector<int>::iterator it = empty_vec.begin(); it != empty_vec.end(); it++)
        std::cout << *it << " "; // No se imprime nada
    std::cout << std::endl;
    
    std::cout << "Searching value in empty vector:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(empty_vec, 42);
        std::cout << "Value found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    /*
        Resumen de nuevas estructuras utilizadas:
        ->std::vector:
            -Estructura: Almacena elementos en un bloque contiguo de memoria.
            -Acceso: Acceso aleatorio rápido. Inserción y eliminación en el final son eficientes, pero no en el principio.

        ->std::list:
            -Estructura: Lista doblemente enlazada con nodos que contienen elementos y punteros a nodos vecinos.
            -Acceso: Acceso secuencial. Inserción y eliminación en ambos extremos son eficientes, pero el acceso aleatorio es lento.

        ->std::deque:
            -Estructura: Bloques de memoria con un mapa que rastrea los bloques, 
                    una estructura interna que permite gestionar múltiples bloques de memoria y acceder a ellos de manera eficiente.
            -Acceso: Acceso aleatorio rápido. Inserción y eliminación en ambos extremos son eficientes.
        
    */
    
    return 0;
}