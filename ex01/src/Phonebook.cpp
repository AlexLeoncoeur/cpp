#include "../include/ex01.hpp"

phonebook::phonebook()
{
	std::cout << "Phonebook constructor called" << std::endl;
	this->ContactAmount = 0;
}

phonebook::~phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
}

int	phonebook::NumberOfContacts()
{
	return (this->ContactAmount);
}

void	phonebook::AddContactNumber()
{
	this->ContactAmount++;
}

void	phonebook::AddToContacts(std::string name, int number)
{
	this->contacts[this->NumberOfContacts() % 8] = contact(name, number);
}

