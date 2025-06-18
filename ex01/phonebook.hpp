/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamini <ahamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:27:43 by ahamini           #+#    #+#             */
/*   Updated: 2025/06/18 12:48:40 by ahamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
        int     count;
        int     index;

	public:
		Phonebook();
        void add_contact();


};
#endif