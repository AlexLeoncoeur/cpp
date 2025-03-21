/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2025/03/21 13:45:36 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "../include/Contact.hpp"

class Phonebook
{
	private:
		static const int maxContacts = 8;
		Contact *contacts[maxContacts];
		int		contactAmount;
	public:
		Phonebook();
		~Phonebook();
		int		numberOfContacts();
		void	addContactNumber();
		void	addToContacts(std::string firstName, std::string lastName, std::string nickname, std::string secret, std::string number);
		Contact** getContacts();
};
