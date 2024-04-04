/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:19 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/04 17:46:18 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

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
        int         _arrayIndex;
        int         _contactIndex;
        void        setValues(std::string value);
        void        getValues();
};



#endif