/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:47 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/18 21:35:54 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
/*
** hoja de correccion
*/
// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }

int main () {
     int intArray[] = {1, 2, 3, 4, 5};
     char charArray[] = {'a', 'b', 'c', 'd', 'e'};
     float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    //No es lo correcto, pero para el ejemplo sirve, simplemente para mostrar que funciona con cualquier tipo de dato
     const char* strsArray1[] = {"hola", "que", "tal", "estas", "?"};
     std::string strArray2[] = {"hola", "que", "tal", "estas", "?"};

    std::cout << "******************" << std::endl;
    std::cout << "*    INT ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(intArray, 5, print<int>);
    
    std::cout << std::endl;
    std::cout << "After addOne:" << std::endl;
    iter(intArray, 5, addOne<int>);
    iter(intArray, 5, print<int>);
    
    std::cout << std::endl;
    std::cout << "After subOne:" << std::endl;
    iter(intArray, 5, subOne<int>);
    iter(intArray, 5, print<int>);
    
    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << "*   CHAR ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(charArray, 5, print<char>);

    std::cout << std::endl;
    std::cout << "After toUpper:" << std::endl;
    iter(charArray, 5, toUpper<char>);
    iter(charArray, 5, print<char>);
    
    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << "*  FLOAT ARRAY   *" << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Original array:" << std::endl;
    iter(floatArray, 5, print<float>);
    
    std::cout << std::endl;
    std::cout << "After addOne:" << std::endl;
    iter(floatArray, 5, addOne<float>);
    iter(floatArray, 5, print<float>);
    
    std::cout << std::endl;
    std::cout << "After subOne:" << std::endl;
    iter(floatArray, 5, subOne<float>);
    iter(floatArray, 5, print<float>);
    std::cout << std::endl;

    std::cout << "******************" << std::endl;
    std::cout << "*  STRS ARRAY    *" << std::endl;
    std::cout << "******************" << std::endl;

    std::cout << "Original array:" << std::endl;
    iter(strsArray1, 5, print<const char*>);

    std::cout << std::endl;

    return 0;
}