/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:40:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/07/21 21:20:41 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

/*   
    Al hacer template <typename T> estamos diciendo que la función es genérica y puede recibir cualquier tipo de contenedor.
    
    typename T::iterator es el tipo de dato que devolverá la función, Un iterador en C++ se comporta de manera similar a un puntero en cuanto
    a que permite acceder y manipular elementos de una colección, pero no es exactamente un puntero.
    
    Los iteradores son objetos que proporcionan una interfaz estandarizada para recorrer y operar sobre elementos en contenedores,
    tales como vectores, listas y mapas. Estos objetos se utilizan para recorrer los elementos de un contenedor, y se pueden utilizar
    para acceder a los elementos, modificarlos, eliminarlos, etc. Es una herramienta versatil que permite trabajar con contenedores de manera
    genérica, sin importar el tipo de contenedor.
    
    En este ejercicio, se asume que el valor que se busca es un entero, por lo que el segundo parámetro de la función es un entero.
    Crearemos una función que reciba un contenedor y un valor, y devuelva un iterador al valor en el contenedor.
    Si el valor no se encuentra en el contenedor, lanzaremos una excepción. 
    
    Utilizaremos std::find para buscar el valor en el contenedor, std::find es una función de la STL que busca el primer elemento en el rango 
    [container.begin(), container.end()) que sea igual al valor dado. El rango se define por begin() y end(), que son funciones de los contenedores
    que devuelven iteradores al principio y al final del contenedor, respectivamente.
    Si no se encuentra, devuelve container.end(), que es un iterador al final del contenedor.
*/
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found"); // ESta excepcion acepta un string como argumento
    return it;
}

#endif