#include "../include/ex01.hpp"

Phonebook::Phonebook()
{
	std::cout << "Phonebook constructor called" << std::endl;
	this->contactAmount = 0;
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i] = nullptr;

	}
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	for (int i = 0; this->contacts[i]; i++)
		delete(this->contacts[i]);
}

int	Phonebook::numberOfContacts()
{
	return (this->contactAmount);
}

void	Phonebook::addContactNumber()
{
	this->contactAmount++;
}

void	Phonebook::addToContacts(std::string firstName,
	std::string lastName, std::string nickname, std::string secret, std::string number)
{
	if (this->contacts[this->numberOfContacts() % 8])
		delete(this->contacts[this->numberOfContacts() % 8]);
	this->contacts[this->numberOfContacts() % 8] = Contact::createContact(firstName, lastName, nickname, secret, number);
}

Contact** Phonebook::getContacts()
{
	return (this->contacts);
}
