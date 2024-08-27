/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:36:11 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/27 22:12:00 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
    En esta ocasion usaremos las extructuras de datos std::vector y std::deque
    La principal diferencia en velocidad radicara en el acceso a los elementos y la insercion de los mismos.
    std::vector tiene una constante más baja debido a su acceso más rápido y coherente, lo que significa que,
    en la práctica, el Merge-Insertion será más rápido con std::vector.
    
    Al tener la necesidad de iterar sobre los elementos de la estructura de datos, de manera constante, std::vector
    es la mejor opción.
    std::vector: Utiliza un bloque continuo de memoria, lo que puede ser más eficiente en cuanto a la utilización de memoria y
                 mejor rendimiento.
                 El acceso secuencial es más rápido, ya que los elementos están contiguos en memoria, aunque la inserción
                 puede ser más lenta, ya que puede requerir la reubicación de todos los elementos en la memoria.
    std::deque: Debido a la estructura segmentada de std::deque, el acceso secuencial puede ser menos eficiente, 
                ya que puede haber saltos entre diferentes bloques de memoria conectados mediante un mapa de punteros.
                Esto hace eficiente en la redimension de la estructura de datos, ya que no necesita copiar todos los elementos.
                Puede requerir más memoria en total debido a la necesidad de gestionar múltiples bloques de memoria y 
                la estructura adicional necesaria para conectarlos. Aunque en insertion puede ser más rápido que std::vector,
                ya que deque esta diseñado para insertar y eliminar elementos de manera eficiente en ambos extremos.
                En la practica std::deque es más lento que std::vector.
       
*/
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [string]" << std::endl;
        return 1;
    } 
    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str += argv[i];
        if (i < argc - 1)
            str += " ";
    }
    PmergeMe pmm(str);
    pmm.init();
    return 0;
}