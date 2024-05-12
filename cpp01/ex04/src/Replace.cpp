/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:57:35 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/12 12:15:05 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/*
    El contructor de la clase Replace recibe tres parámetros en su lista de inicializacion:
    - infile: el nombre del archivo de entrada
    - s1: la cadena a buscar
    - s2: la cadena a reemplazar
    El constructor también inicializa el nombre del archivo de salida con el nombre del archivo de entrada
    seguido de ".replace".
    -En el subject no dejan usar las funciones tipicas de open write etc, por lo que se utilizan las clases
        ifstream y ofstream, que son clases de la biblioteca estándar de C++ que se utilizan para leer y escribir archivos.
        y consisten en:
            -ifstream: se utiliza para leer archivos.
            -ofstream: se utiliza para escribir archivos.
        Estas clases tiene metodos para abrir, cerrar, leer y escribir archivos. Asi como para encontrar y reemplazar cadenas.
        Los metodos de estas clases son muy similares a los de las clases cin y cout, con la diferencia de que se utilizan para
        leer y escribir archivos en lugar de la consola.
    -Para abrir el archivo de entrada se utiliza la clase ifstream, creando el objeto infile.
    -La clase ifstream recibe como parámetro un puntero a un array de caracteres, por lo que se utiliza
        this->_infile.c_str() convierte el string _infile a un puntero de caracteres, estilo C.
    -Con getline(infile, line) se lee una línea del archivo de entrada y se almacena en la variable line.
*/

Replace::Replace(std::string infile, std::string s1, std::string s2) : _infile(infile), _s1(s1), _s2(s2) {
    this->_outfile = this->_infile + ".replace";
}

Replace::~Replace() {}

int Replace::replaceString() {
    std::ifstream infile(this->_infile.c_str()); // Abrir el archivo de entrada
    std::ofstream outfile(this->_outfile.c_str()); // Crear el archivo de salida
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << this->_infile << std::endl;
        return 1;
    }
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << this->_outfile << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(infile, line))
    {
        size_t pos = line.find(_s1);
        while (pos != std::string::npos) {
            // Construir la nueva línea con s2 en lugar de s1
            line = line.substr(0, pos) + _s2 + line.substr(pos + _s1.length());
            // Buscar la siguiente ocurrencia de s1
            pos = line.find(_s1, pos + _s2.length());
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}