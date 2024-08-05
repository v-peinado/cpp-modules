/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:32:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/08/05 17:38:53 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double>  _data;       
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        
        /* Exchange */
        void startExchange(std::string filename);

        /* Parse files */
        void parseDbFile(std::string filename);
        void parseInputFile(std::string filename);
        std::string to_string(int i);
        bool invalidLineFormat(std::string line);
        bool is_valid_date(std::string date);

        /* Print */
        void printDb() const;   
};

#endif