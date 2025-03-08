#include "../include/ex01.hpp"

Phonebook::phonebook()
{
	std::cout << "Phonebook constructor called" << std::endl;
	this->contactAmount = 0;
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i] = nullptr;

	}
}

Phonebook::~phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	for (int i = 0; this->contacts[i]; i++)
		delete(this->contacts[i]);
}

int	Phonebook::numberOfContacts()
{
	return (this->ContactAmount);
}

void	Phonebook::AddContactNumber()
{
	this->ContactAmount++;
}

void	Phonebook::AddToContacts(std::string firstName,
	std::string lastName, std::string nickname, std::string secret, std::string number)
{
	if (this->contacts[this->NumberOfContacts() % 8])
		delete(this->contacts[this->NumberOfContacts() % 8]);
	this->contacts[this->NumberOfContacts() % 8] = contact::createContact(firstName, lastName, nickname, secret, number);
}

contact** Phonebook::getContacts()
{
	return (this->contacts);
}
