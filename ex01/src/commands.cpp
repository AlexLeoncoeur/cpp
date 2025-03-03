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

}
