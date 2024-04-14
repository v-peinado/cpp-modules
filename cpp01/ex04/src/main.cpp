/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:00:41 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 17:21:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char *argv[]) {
    if (argc == 4) {
        Replace replace(argv[1], argv[2], argv[3]);
        if(!replace.replaceString())
            std::cout << "File " << argv[1] << " has been successfully replaced." << std::endl;
        else
        {
            std::cerr << "Error: File " << argv[1] << " could not be replaced." << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
        return 1;
    }
    return 0;
}