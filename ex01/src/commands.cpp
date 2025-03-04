#include "../include/ex01.hpp"

static int	checkDigit(std::string number)
{
	for (int i = 0; i < number.size(); i++)
		if (!std::isdigit(number[i]))
			return (1);
	return (0);
}

void	Add(phonebook *phoneB)
{
	std::string	firstName;
	std::string	lastName;
	std::string	number;

	std::cout << "Creating new contact:" << std::endl << "Introduce first name:" << std::endl;
	std::cin >> firstName;
	if (firstName.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Introduce  last name:" << std::endl;
	std::cin >> lastName;
	if (lastName.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Introduce number:" << std::endl;
	std::cin >> number;
	if (number.empty() || checkDigit(number))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	phoneB->AddToContacts(firstName, lastName, number);
	phoneB->AddContactNumber();
}

static void	putLine(contact  **contacts, std::string aContactData, int i)
{
	bool	stop = 0;

	std::cout << "|";
	for (int j = 0; j < aContactData.size(); j++)
	{
		if (aContactData.size() < 10)
		{
			for (int k = 0; stop == 0 && k < (10 - aContactData.size()); k++)
				std::cout << " ";
			stop = 1;
		}
		if (j == 10 && aContactData[j + 1])
		{
			std::cout << ".";
			break ;
		}
		std::cout << aContactData[j];
	}
	std::cout << "|";
}

static void	putColumns(phonebook *phoneB)
{
	contact 	**contacts = phoneB->getContacts();

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|----------||----------||----------||----------|" << std::endl;
		if (contacts[i])
		{
			putLine(contacts, "0" + i, i);
			putLine(contacts, contacts[i]->getFirstName(), i);
			putLine(contacts, contacts[i]->getLastName(), i);
			putLine(contacts, contacts[i]->getNumber(), i);
			std::cout << std::endl << "|----------||----------||----------||----------|" << std::endl;
		}
	}
}

void	Search(phonebook *phoneB)
{
	putColumns(phoneB);
}
