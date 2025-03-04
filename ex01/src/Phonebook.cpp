#include "../include/ex01.hpp"

phonebook::phonebook()
{
	std::cout << "Phonebook constructor called" << std::endl;
	this->ContactAmount = 0;
	for (int i = 0; i < 8; i++)
		this->contacts[i] = NULL;
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

void	phonebook::AddToContacts(std::string firstName, std::string lastName, std::string number)
{
	this->contacts[this->NumberOfContacts() % 8] = contact::createContact(firstName, lastName, number);
}

contact** phonebook::getContacts()
{
	return (this->contacts);
}
