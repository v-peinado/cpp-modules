/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:08 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/27 19:59:32 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <cstdio>
#include <typeinfo>
#include <set>

class PmergeMe
{
    private:
        std::deque<unsigned int> _values_1;
        std::vector<unsigned int> _values_2;
        bool alreadyPrinted;
        
        std::string _str;
        std::string toString(unsigned int value);
        int calculateThreshold(int threshold);

        /*****************
        *   TEMPLATES    *
        *****************/
        /******************************************************************************************* 
            Parseo de valores y utilidades para imprimir y comprobar si un contenedor está ordenado.
        *********************************************************************************************/
       
        template <typename STL>
        void iterPrint(STL &container)
        {
            for (typename STL::iterator it = container.begin(); it != container.end(); it++)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        
        template <typename STL>
        bool isSorted(STL &container)
        {
            typename STL::const_iterator it = container.begin();
            while (it != container.end() - 1)
            {
                if (*it > *(it + 1))
                    return false;
                ++it;
            }
            return true;
        }

        template <typename STL>
        bool notRepeated(STL &container)
        {
            // Crear un set para almacenar los elementos únicos
            std::set<int> unique_elements;

            typename STL::iterator it;
            for (it = container.begin(); it != container.end(); ++it)
            {
                // Es un par que contiene un iterador a la posición del elemento y un booleano, al insertar un elemento en el set(el iterador),
                //si el elemento ya estaba en el set, el booleano será false
                std::pair<std::set<int>::iterator, bool> result = unique_elements.insert(*it);               
                // Si la inserción falla, result.second será false, lo que significa que el elemento ya estaba en el set
                if (!result.second)
                {
                    return false;
                }
            }
                return true; // No hay elementos repetidos
        }

        template <typename STL>
        void parseValues(std::string &str, STL &container) {
            std::stringstream ss(str);
            std::string token;
            

            if (str.empty())
                throw std::invalid_argument("Empty string");
            while (ss >> token)
            {
                std::stringstream tokenStream(token);
                int value;

                // Comprobar si el token es un número entero válido
                if (!(tokenStream >> value) || value < 0 || !tokenStream.eof() || tokenStream.fail())
                    throw std::invalid_argument("Invalid number: " + token);
                // Añadir el número a las estructuras de datos
                container.push_back(value);
            }
            if (container.size() == 1)
                    throw std::runtime_error("Only one element in the container");
            if (isSorted(container)) 
                    throw std::runtime_error("Container is already sorted");
            if (!notRepeated(container))
                    throw std::runtime_error("Container has repeated elements");
            fordJohnson(container, 0, container.size() -1);
        }
        

        /********************************************************* 
            Comienzo de la aplicacion del algoritmo de ordenación.
        **********************************************************/
       /*
            Función para fusionar dos subvectores ordenados en el contenedor original.
            Los subvectores están delimitados por los índices 'left', 'mid' y 'right'.
            Comparamos y fusionamos los elementos de los subvectores izquierdo y derecho en el contenedor original.
            La fusión de sublistas ordenadas, como [1, 4, 7] y [2, 5], es una parte clave del algoritmo de ordenación por mezcla (merge sort).
            El objetivo es combinar estas dos sublistas en una sola lista ordenada. Aquí te explico cómo se hace:
            Usa tres índices: uno para recorrer la primera sublista (i), otro para la segunda sublista (j), y otro para el contenedor fusionado (k).
            
        Paso 1: Inicializa índices:
            i = 0 (para [1, 4, 7])
            j = 0 (para [2, 5])
            k = 0 (para la lista fusionada)
        Paso 2: Comienza a comparar y copiar:
            -Compara 1 (de [1, 4, 7]) y 2 (de [2, 5]). 1 es menor, así que se copia 1 al contenedor fusionado.
            -Incrementa i y k. Ahora i = 1, k = 1.
            -Compara 4 (de [1, 4, 7]) y 2 (de [2, 5]). 2 es menor, así que se copia 2 al contenedor fusionado.
            -Incrementa j y k. Ahora j = 1, k = 2.
            -Compara 4 (de [1, 4, 7]) y 5 (de [2, 5]). 4 es menor, así que se copia 4 al contenedor fusionado.
            -Incrementa i y k. Ahora i = 2, k = 3.
            -Compara 7 (de [1, 4, 7]) y 5 (de [2, 5]). 5 es menor, así que se copia 5 al contenedor fusionado.
            -Incrementa j y k. Ahora j = 2, k = 4.
        Paso 3: Copia los elementos restantes:
            i ha llegado al final de la primera sublista,
            pero j aún tiene elementos restantes en [2, 5]. Como no quedan elementos en la primera sublista,
            simplemente copia el resto de la segunda sublista (7 en este caso).
       */
        template <typename Container>
        void merge(Container &arr, int left, int mid, int right)
        {   
            //Calculamos el tamaño de los subvectores
            int n1 = mid - left + 1;
            int n2 = right - mid;

            //Creamos dos subvectores temporales
            Container leftSubvec(arr.begin() + left, arr.begin() + left + n1);
            Container rightSubvec(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

            //Inicializamos los indices de los subvectores
            int i = 0, j = 0, k = left;
            
            //Iremos comparando los elementos de los subvectores y los iremos añadiendo al contenedor original
            while (i < n1 && j < n2) //si i o j llegan al final de su subvector, se saldra del bucle
            {
                //Si el elemento del subvector izquierdo es menor o igual que el del subvector derecho, se añade al contenedor original
                if (leftSubvec[i] <= rightSubvec[j])
                    arr[k++] = leftSubvec[i++];
                else
                    arr[k++] = rightSubvec[j++];
            }
            //si quedan elementos en el subvector izquierdo, o derecho se añaden al contenedor original
            while (i < n1)
                arr[k++] = leftSubvec[i++];

            while (j < n2)
                arr[k++] = rightSubvec[j++];
        }
        /*
            insertion sort es especialmente eficaz para listas pequeñas, 
            consiste en recorrer la lista de elementos de izquierda a derecha,
            y a medida que avanza, inserta el elemento actual en su posición correcta en la lista ordenada.
            
            -Supongamos que tenemos un std::vector<int> con los valores {4, 3, 5, 1, 2} y queremos ordenarlo con la función insertionSort:
                Primera Iteración (i = 1):
                    currentValue = 3
                    Comparamos 3 con 4, movemos 4 a la posición 1, luego insertamos 3 en la posición 0.
                    Resultado parcial: [3, 4, 5, 1, 2].

                Segunda Iteración (i = 2):
                    currentValue = 5
                    5 está en la posición correcta porque 5 es mayor que 4.
                    Resultado parcial sigue siendo: [3, 4, 5, 1, 2].

                Tercera Iteración (i = 3):
                    currentValue = 1
                    Movemos 5, 4, y 3 a la derecha, luego insertamos 1 en la posición 0.
                    Resultado parcial: [1, 3, 4, 5, 2].

                Cuarta Iteración (i = 4):
                    currentValue = 2
                    Movemos 5, 4, y 3 a la derecha, luego insertamos 2 en la posición 1.
                    Resultado final: [1, 2, 3, 4, 5].
        */
        template <typename Container>
        void insertionSort(Container &arr, int left, int right) 
        {
            // Iteramos desde el segundo elemento hasta el último elemento del contenedor
            for (int i = left + 1; i <= right; ++i) 
            {
                // Tomamos el valor del elemento actual que vamos a insertar en la parte ordenada
                //usar typename para indicar que se trata de un tipo dependiente de un template
                typename Container::value_type currentValue = arr[i];
                
                // Inicializamos un índice j que apunta al elemento justo antes del actual
                int j = i - 1;
                
                // Mientras el índice j sea mayor o igual que el primer elemento de la parte ordenada 
                //y el elemento actual sea menor que el elemento en la posición j del contenedor cambiaremos los elementos de posición
                //mientras el primer valors sea mayor que el segundo, se intercambiaran, se repetira hasta que se cumpla la condicion
                while (j >= left && arr[j] > currentValue) 
                {
                    arr[j + 1] = arr[j];
                    --j;  // Decrementamos j para continuar la comparación con los elementos anteriores
                }
                
                // Colocamos currentValue en la posición correcta dentro de la parte ordenada del contenedor
                arr[j + 1] = currentValue;
            }
        }

       /*
            Esta funcion se encargara de dividir el contenedor en dos partes, y se llamara recursivamente a si misma para dividirlo en mas partes.
            La primera division generados dos subcontenedores, y recursivamente se dividiran en mas subcontenedores hasta que el tamaño del contenedor sea menor o igual al umbral.
            El umbral es el tamaño de la division a partir del cual el algoritmo decide dejar de usar la estrategia principal de ordenación (en este caso, 
            merge sort) y cambiar a una estrategia de ordenación más simple y rápida para pequeños conjuntos de datos, como la ordenación por inserción (insertion sort)
            
            --Explicación de Recursividad con Merge y LIFO--
            Imagina que la función recursiva es como una serie de tareas pendientes apiladas en una pila. 
            Cada vez que la función se llama a sí misma, se añade una nueva tarea a la pila. 
            La función no puede terminar de ejecutarse hasta que todas las tareas en la pila se hayan resuelto. 
            Cuando la función se llama a sí misma, el flujo de la ejecución actual se "pausa" y no se retoma hasta que la recursión se ha "desenrollado".

            Fusión (Merge): La fusión solo ocurre después de que todas las llamadas recursivas dentro de una rama particular hayan retornado. 
            No se fusiona nada hasta que ambas mitades de la lista estén completamente ordenadas. 
            Es decir, el merge solo se ejecuta una vez que las sublistas ya han sido ordenadas por las llamadas recursivas correspondientes.
            
            En la recursividad, cada llamada a la función crea una nueva "capa" de ejecución. 
            La ejecución solo avanza cuando las capas más internas (los casos base) se resuelven, permitiendo que el flujo de la función retome y 
            finalmente llame a merge para fusionar los resultados.
            
            En este sentido, la recursividad funciona como una pila LIFO (Last In, First Out). Cuando se llama a la función recursiva, 
            se queda pendiente un merge hasta que se resuelvan todas las llamadas recursivas. Una vez resueltas todas las llamadas recursivas, 
            se va haciendo el merge desde la última llamada recursiva hasta la primera, porque el proceso de fusión no puede comenzar hasta que se haya completado
            la ordenación de todas las sublistas en la pila.

            En resumen, las llamadas recursivas se apilan en la memoria y se resuelven en orden inverso al que fueron hechas.
            La fusión (merge) se efectúa cuando la pila de ejecución comienza a "desenrollarse", comenzando con las llamadas más recientes. 
            Así, cada llamada a merge trabaja con los resultados de las llamadas recursivas previas,
            uniendo las partes ordenadas hasta que todo el contenedor esté completamente ordenado.
        

            mergeInsert(container, left, right)  // Llamada inicial
            |
            |--- Si (right - left + 1) <= umbral: 
            |        |--- Ordena usando insertionSort
            |
            |--- Si no:
            |        |--- Calcula mid = (left + right) / 2
            |        |
            |        |--- Llama a mergeInsert(container, left, mid)  // Parte izquierda
            |        |         |
            |        |         |--- Recursividad hasta que se cumpla umbral
            |        |
            |        |--- Llama a mergeInsert(container, mid + 1, right)  // Parte derecha
            |                  |
            |                  |--- Recursividad hasta que se cumpla umbral
            |
            |--- Llama a merge(container, left, mid, right)  // Fusión final de las partes
       
       */
       template <typename STL>
        void mergeInsert(STL &container, int left, int right)
        {
            if (left < right)
            {
                //Si el tamaño del contenedor es menor o igual al umbral, se ordena con insertionSort
                if (right - left + 1 <= calculateThreshold(right - left + 1)) 
                {
                    insertionSort(container, left, right); 
                }
                else
                {
                    //Dividir el contenedor en dos partes
                    int mid = left + (right - left) / 2;
                    //Llamada recursiva a si misma, con la primera mitad del contenedor
                    mergeInsert(container, left, mid);
                    //Llamada recursiva a si misma, con la segunda mitad del contenedor
                    mergeInsert(container, mid + 1, right);
                    /*
                         Cuando la recursividad ya no puede dividir más la lista (es decir, cuando las sublistas tienen solo un elemento 
                         o cuando el umbral para usar la ordenación por inserción es alcanzado), la función mergeInsert comienza a retornar y,
                          en ese punto, se llama a merge, que estaba esperando en la lista de recursividad y unira las partes.
                    */
                    merge(container, left, mid, right);
                }
            }
        }
        
        /*
            Funcion principal que llama a las funciones de ordenacion, recibira un contenedor y el rango de elementos a ordenar.
            se comprobara si solo hay un elemento, si ya esta ordenado o si hay elementos repetidos.
            Si supera todas las comprobaciones se procedera a ordenar el contenedor.
            Se mostrara el contenedor antes y despues de la ordenacion, el tipo de contenedor, su tamaño y el tiempo que ha tardado en ordenasrse.
        */
        template <typename STL>
        void fordJohnson(STL &container, int start, int end)
        {        
            if (this->alreadyPrinted == false)
            {
                std::cout << "Before: ";
                iterPrint(container);
            }
            clock_t start_time = clock(); // clock da el tiempo de ejecucion del programa en ciclos de CPU, se debe dividir por CLOCKS_PER_SEC para obtener el tiempo en segundos
            //Comenzar a ordenar
            mergeInsert(container, start, end);
            clock_t end_time = clock();
            
            if (isSorted(container)) 
            {
                if (this->alreadyPrinted == false)
                {
                std::cout << "After: ";
                iterPrint(container);
                this->alreadyPrinted = true;
                }
                if (typeid(container) == typeid(std::deque<unsigned int>))
                    std::cout << "Time to process a range of " << container.size() << " elements with std::deque is: ";
                else if (typeid(container) == typeid(std::vector<unsigned int>))
                    std::cout << "Time to process a range of " << container.size() << " elements with std::vector is: ";
                // si queremos mostrar el tiempo en segundos devemos dividirlo por CLOCKS_PER_SEC
                // si queremos en ms deberemos dividir clock_t por CLOCKS_PER_SEC y multiplicarlo por 1000
                std::cout  << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << " ms\n";
            } else
                throw std::runtime_error("Johnson failed");        
        }
       
        PmergeMe();
    public:
        PmergeMe(std::string &str);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &rhs);
        
        void init();       
};


#endif