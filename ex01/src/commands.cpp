#include "../include/ex01.hpp"

void	Add(phonebook phoneB)
{
	std::string	name;
	char		*number;

	std::cout << "Creating new contact:" << std::endl << "Introduce name:" << std::endl;
	std::cin >> name;
	std::cout << "Introduce number:" << std::endl;
	std::cin >> number;
	phoneB.AddToContacts(name, std::atoi(number));
	phoneB.AddContactNumber();
}

void	Search(phonebook phoneB)
{
	for (int i = 0; i < 8; i++)
		if (searchname == phoneB.GetName(i))
			break;
	if (searchname == phoneB.GetName(i))
	{
		std::cout << "Contact: " << searchname << std::endl;
		std::cout << "Phone Number: " << phoneB.getNumber(i) << std::endl;
	}
}
//Mirar subject para ver que necesita search de input (nombre)