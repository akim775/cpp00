/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:32:20 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/23 10:14:40 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	Phonebook phonebook;
	std::string command;
	
	std::cout << "Welcome into The Awesome PhoneBook !" << std::endl;
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
			phonebook.search_contact();
		else
			std::cout << "Unknown command.\n";
	}
}
