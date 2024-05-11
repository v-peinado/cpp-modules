/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:19 by vpeinado          #+#    #+#             */
/*   Updated: 2024/05/11 16:05:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
        std::string _name;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        int only_spaces(std::string str);

    public:
        Contact();
        ~Contact();
        int         _arrayIndex; //sera el indice del array de contactos, para saber su posicion al buscarlo
        int         _contactIndex; //sera el indice real del contacto , para saber cual es el mas antiguo
        void        setValues(std::string value);
        void        getValues();
};



#endif