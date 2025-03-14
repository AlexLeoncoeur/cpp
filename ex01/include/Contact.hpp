/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2025/03/14 12:49:09 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Contact
{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string secret;
	std::string number;
	public:
		Contact();
		Contact(std::string firstName,
			std::string lastName, std::string nickname, std::string secret, std::string number);
		~Contact();
		std::string	getNumber();
		std::string	getFirstName();
		std::string	getLastName();
		std::string getNickname();
		std::string getSecret();
		static Contact* createContact(std::string firstName,
			std::string lastName, std::string nickname, std::string secret, std::string number);
};
