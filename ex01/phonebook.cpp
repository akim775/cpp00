/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:16:32 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/23 11:03:24 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook() : count(0), index(0) {}

void Phonebook::add_contact() {
	contacts[index % 8].set_contact();
	index++;
	if (count < 8)
		count++;
}

void print_field(const std::string& str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Phonebook::search_contact() const
{
	if (count == 0)
	{
		std::cout << "No contacts in the phonebook.\n";
		return;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
	std::cout << "---------------------------------------------\n";
	int i = 0;
	while (i < count)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		print_field(contacts[i].get_first_name()); std::cout << "|";
		print_field(contacts[i].get_last_name()); std::cout << "|";
		print_field(contacts[i].get_nickname()); std::cout << "|\n";
		i++;
	}
	std::cout << "---------------------------------------------\n";
	
	std::string input;
	int idx = -1;
	bool valid = false;

	while (!valid)
	{
		std::cout << "Enter the index of the contact to view:\n> ";
		std::getline(std::cin, input);

		if (std::cin.eof())
			return ;
		int j = 0;
		while (input[j])
		{
			if (!std::isdigit(static_cast<unsigned char>(input[j])))
				break;
			j++;
		}

		if (j == static_cast<int>(input.length()) && input.length() > 0)
		{
			idx = 0;
			int k = 0;
			while (input[k])
			{
				idx = idx * 10 + (input[k] - '0');
				k++;
			}

			if (idx >= 0 && idx < count)
				valid = true;
			else
				std::cout << "Invalid index. Please try again.\n";
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid number.\n";
		}
	}

	contacts[idx].print_full_contact();
}
