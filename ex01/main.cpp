/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:32:20 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/18 12:29:54 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	Phonebook phonebook;
	std::string command;
	
	std::cout << "Welcome into the awesome PhoneBook !" << std::endl;
	std::cout << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << std::endl;

	while (true)
	{
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		if (command == "EXIT")
			return (0);
		if (command == "ADD")
		{
			phonebook.add_contact();
		}
		else if (command == "SEARCH")
			std::cout << "Search not implemented yet.\n";
		else
			std::cout << "Unknown command.\n";
	}
}
