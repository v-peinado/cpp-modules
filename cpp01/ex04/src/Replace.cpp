/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:57:35 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 18:07:04 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string infile, std::string s1, std::string s2) : _infile(infile), _s1(s1), _s2(s2) {
    this->_outfile = this->_infile + ".replace";
}

Replace::~Replace() {}

int Replace::replaceString() {
    std::ifstream infile(this->_infile.c_str());
    std::ofstream outfile(this->_outfile.c_str());
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