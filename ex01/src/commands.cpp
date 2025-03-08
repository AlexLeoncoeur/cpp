#include "../include/ex01.hpp"

static int	checkDigit(std::string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if (i == 0 && number[i] == '+')
			i++;
		if (!std::isdigit(number[i]))
			return (1);
	}
	return (0);
}

void	add(Phonebook *phoneB)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	secret;
	std::string	number;

	std::cout << "Creating new contact:" << std::endl << "Introduce first name:" << std::endl;
	std::cin >> firstName;
	if (firstName.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Introduce last name:" << std::endl;
	std::cin >> lastName;
	if (lastName.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Introduce nickname:" << std::endl;
	std::cin >> nickname;
	if (nickname.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Introduce darkest secret:" << std::endl;
	std::cin >> secret;
	if (secret.empty())
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
	phoneB->addToContacts(firstName, lastName, nickname, secret, number);
	phoneB->addContactNumber();
}

static std::string intToString(int nb)
{
	char		buffer[2];

	sprintf(buffer, "%d", nb);
	return ((std::string)(buffer));

}

static int	checkContactContent(Contact *contact)
{
	if (contact->getFirstName().empty() || contact->getLastName().empty()
		|| contact->getNumber().empty() || contact->getSecret().empty() || contact->getNickname().empty())
		return (0);
	return (1);
}

static void	searchInput(Phonebook *phoneB)
{
	std::string	index;
	Contact 	**contacts;
	
	std::cout << "Input desired contact's index: " << std::endl;
	std::cin >> index;
	if (std::cin.eof())
		phoneB->~Phonebook(), std::exit(0);
	if (index.empty() || checkDigit(index) || std::atoi(index.c_str()) > 7 || std::atoi(index.c_str()) < 0)
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (phoneB->numberOfContacts() == 0 || std::atoi(index.c_str()) >= phoneB->numberOfContacts() || std::atoi(index.c_str()) > 7)
	{
		std::cout << "No contact data" << std::endl;
		return ;
	}
	contacts = phoneB->getContacts();
	std::cout << "Contact first name: " << contacts[std::atoi(index.c_str())]->getFirstName() << std::endl;
	std::cout << "Contact last name: " << contacts[std::atoi(index.c_str())]->getLastName() << std::endl;
	std::cout << "Contact nickname: " << contacts[std::atoi(index.c_str())]->getNickname() << std::endl;
	std::cout << "Contact secret: " << contacts[std::atoi(index.c_str())]->getSecret() << std::endl;
	std::cout << "Contact phone number: " << contacts[std::atoi(index.c_str())]->getNumber() << std::endl;
}

static void	putLine(Contact  **contacts, std::string aContactData, int i)
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
		if (j == 9 && aContactData[j + 1])
		{
			std::cout << ".";
			break ;
		}
		std::cout << aContactData[j];
	}
}

static void	putColumns(Phonebook *phoneB)
{
	Contact 	**contacts = phoneB->getContacts();

	std::cout << "|-----Index|------Name|---Surname|Phone num.|" << std::endl;
	for (int i = 0; i < 8 && contacts[i] && checkContactContent(contacts[i]); i++)
	{
			putLine(contacts, intToString(i), i);
			putLine(contacts, contacts[i]->getFirstName(), i);
			putLine(contacts, contacts[i]->getLastName(), i);
			putLine(contacts, contacts[i]->getNumber(), i);
			std::cout << "|";
			std::cout << std::endl << "|----------|----------|----------|----------|" << std::endl;
	}
}

void	search(Phonebook *phoneB)
{
	putColumns(phoneB);
	searchInput(phoneB);
}
