/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:08 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/25 22:09:19 by vpeinado         ###   ########.fr       */
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
        std::string _str;
        std::string to_string(unsigned int value);
        int calculateThreshold(int threshold);

        /*****************
        *   TEMPLATES    *
        *****************/
        /******************************************************************************************* 
            Parseo de valores y utilidades para imprimir y comprobar si un contenedor está ordenado.
        *********************************************************************************************/
       
        template <typename STL>
        void iter_print(STL &container)
        {
            for (typename STL::iterator it = container.begin(); it != container.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        
        template <typename STL>
        bool is_sorted(STL &container)
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
        bool notRepeated(STL &container) {
            std::set<int> unique_elements;  // Trabajamos con enteros

            typename STL::iterator it;
            for (it = container.begin(); it != container.end(); ++it) {
                // Intentar insertar el entero en el set
                std::pair<std::set<int>::iterator, bool> result = unique_elements.insert(*it);
                
                // Si la inserción falla, el elemento está repetido
                if (!result.second) {
                    return false;
                }
            }

                return true; // No hay elementos repetidos
        }

        template <typename STL>
        void parse_values(std::string &str, STL &container) {
            std::stringstream ss(str);
            std::string token;
            char delimiter = ' ';

            if (str.empty())
                throw std::invalid_argument("Empty string");
            // Iterar sobre los tokens separados por espacios
            while (std::getline(ss, token, delimiter)) {
                std::stringstream tokenStream(token);
                int value;

                // Comprobar si el token es un número entero válido
                if (!(tokenStream >> value) || value < 0 || tokenStream.peek() != EOF)
                    throw std::invalid_argument("Invalid number: " + token);
                // Añadir el número a las estructuras de datos
                container.push_back(value);
            }
            //iter_print(container);
            fordJohnson(container, 0, container.size() -1);
        }
        

        /********************************************************* 
            Comienzo de la aplicacion del algoritmo de ordenación.
        **********************************************************/

        template <typename Container>
        void merge(Container &arr, int left, int mid, int right)
        {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            Container leftSubvec(arr.begin() + left, arr.begin() + left + n1);
            Container rightSubvec(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

            int i = 0, j = 0, k = left;

            while (i < n1 && j < n2)
            {
                if (leftSubvec[i] <= rightSubvec[j])
                    arr[k++] = leftSubvec[i++];
                else
                    arr[k++] = rightSubvec[j++];
            }

            while (i < n1)
                arr[k++] = leftSubvec[i++];

            while (j < n2)
                arr[k++] = rightSubvec[j++];
        }

       	template <typename Container>
        void insertionSort(Container &arr, int left, int right)
        {
            for (int i = left + 1; i <= right; i++)
            {
                typename Container::value_type key = arr[i];
                int j = i - 1;
                while (j >= left && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
       
       template <typename STL>
        void mergeInsert(STL &container, int left, int right){
            if (left < right){
                if (right - left + 1 <= calculateThreshold(right - left + 1)) {
                    insertionSort(container, left, right);
                }
                else{
                    int mid = left + (right - left) / 2;
                    mergeInsert(container, left, mid);
                    mergeInsert(container, mid + 1, right);
                    merge(container, left, mid, right);
                }
            }
        }
        
        template <typename STL>
        void fordJohnson(STL &container, int start, int end)
        {           
            if (start == end)
                    throw std::invalid_argument("Only one element in the container");
            if (is_sorted(container)) 
                    throw std::invalid_argument("Container is already sorted");
            if (!notRepeated(container))
                    throw std::invalid_argument("Container has repeated elements");
            std::cout << "Before Johnson: ";
            iter_print(container);
            clock_t start_time = clock();
            mergeInsert(container, start, end);
            clock_t end_time = clock();
            
            std::cout << "After Johnson: ";
            if (is_sorted(container)) {
                iter_print(container);
                if (typeid(container) == typeid(std::deque<unsigned int>))
                    std::cout << "Type: std::deque\n";
                else if (typeid(container) == typeid(std::vector<unsigned int>))
                    std::cout << "Type: std::vector\n";
                std::cout << "Size: " << container.size() << std::endl;
                std::cout << "Time: " << static_cast<double>(end_time - start_time) / (CLOCKS_PER_SEC / 1000) << " us\n";
            } else
                throw std::invalid_argument("Johnson failed");
            std::cout << std::endl;
            std::cout << std::endl;            
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