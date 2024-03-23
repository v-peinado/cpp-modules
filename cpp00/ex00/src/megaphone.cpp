/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:14:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/20 19:48:52 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    std::string message;
    
    if(argc == 1)
        message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
        message += argv[i];
    for (std::string::iterator it = message.begin(); it != message.end(); it++)
        *it = std::toupper(*it);
    std::cout << message << std::endl;
    return (0);
}
