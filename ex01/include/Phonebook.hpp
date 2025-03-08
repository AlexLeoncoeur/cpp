/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2025/03/03 19:44:02 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "ex01.hpp"

class Phonebook
{
	private:
		Contact *contacts[8];
		int		contactAmount;
	public:
		Phonebook();
		~Phonebook();
		int		numberOfContacts();
		void	initContacts(Phonebook phoneB);
		void	addContactNumber();
		void	addToContacts(std::string firstName, std::string lastName, std::string nickname, std::string secret, std::string number);
		Contact** getContacts();
};

#endif