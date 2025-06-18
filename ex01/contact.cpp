/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:18:53 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/18 13:04:20 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	is_valid_number(const std::string& str)
{
	size_t i = 0;
	if (str[0] == '\0')
		return (false);
	if (!std::isdigit(static_cast<unsigned char>(str[0])))
	{
		std::cout << "Phone number start with a digit" << std::endl;
		return false;
	}
	while (str[i]) {
		char c = str[i];
		if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			std::cout << "Phone number can only contain digits" << std::endl;
			return false;
		}
		i++;
    }
	if (i != 10)
	{
			std::cout << "Phone number can only contain  10 digits" << std::endl;
			return false;
	}
	return true;
}

bool	is_valid_name(const std::string& str)
{
	size_t i = 0;
	if (str[0] == '\0')
		return (false);
	if (!std::isupper(static_cast<unsigned char>(str[0])))
	{
		std::cout << "Name start with an uppercase" << std::endl;
		return false;
	}
	while (str[i]) {
		char c = str[i];
		if (!std::isalpha(static_cast<unsigned char>(c)) && c != '-' && c != '\'')
		{
			std::cout << "Name can only contain letters, *-* and *'*" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

void	Contact::set_contact()
{
	std::cout << "Please enter the contact's first name:\n> ";
	std::getline(std::cin, first_name);
	if (std::cin.eof())
		return ;
	if (!is_valid_name(first_name))
		return ;
	std::cout << "Please enter the contact's last name:\n> ";
	std::getline(std::cin, last_name);
	if (std::cin.eof())
		return ;
	if (!is_valid_name(last_name))
		return ;
	std::cout << "Please enter the contact's nickname:\n> ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;
	if (!is_valid_name(nickname))
		return ;
	std::cout << "Please enter the contact's phone number:\n> ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
		return ;
	if (!is_valid_number(phone_number))
		return ;
	std::cout << "Please enter the contact's darkest secret:\n> ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
		return ;
}
