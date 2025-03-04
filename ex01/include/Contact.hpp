/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2025/03/03 19:45:54 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "ex01.hpp"

class contact
{
	private:
		std::string number;
		std::string firstName;
		std::string lastName;
	public:
		contact();
		contact(std::string firstName, std::string secondName, std::string number);
		~contact();
		std::string	getNumber();
		std::string	getFirstName();
		std::string	getLastName();
		static contact* createContact(std::string firstName, std::string secondName, std::string number);
};

#endif