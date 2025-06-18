/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:16:32 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/18 12:35:34 by ahamini          ###   ########.fr       */
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