/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:31:24 by aarenas-          #+#    #+#             */
/*   Updated: 2025/03/03 19:45:15 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EX01_HPP
# define EX01_HPP

# include <iostream>
# include <cctype>
# include <cstring>
# include <cstdlib>
# include "Contact.hpp"
# include "Phonebook.hpp"

void	add(Phonebook *phoneB);
void	search(Phonebook *phoneB);

#endif