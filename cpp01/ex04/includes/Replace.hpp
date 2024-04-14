/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:30:54 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/14 21:35:46 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace {
    private:
        std::string _infile;
        std::string _outfile;
        std::string _s1;
        std::string _s2;
    public:
        Replace(std::string infile, std::string s1, std::string s2);
        ~Replace();
        int replaceString();
};

#endif