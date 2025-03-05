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

class phonebook
{
	private:
		contact *contacts[8];
		int		ContactAmount;
	public:
		phonebook();
		~phonebook();
		int		NumberOfContacts();
		void	initContacts(phonebook phoneB);
		void	AddContactNumber();
		void	AddToContacts(std::string firstName, std::string lastName, std::string nickname, std::string secret, std::string number);
		contact** getContacts();
};

#endif