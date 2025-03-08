#include "../include/ex01.hpp"

Contact::Contact()
{
	std::cout << "Contact default constructor called." << std::endl;
}

Contact::Contact(std::string firstName,
	std::string lastName, std::string nickname, std::string secret, std::string number)
{
	std::cout << "Contact alternative constructor called." << std::endl;
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->secret = secret;
	this->number = number;
}

Contact::~Contact()
{
	std::cout << "Contact default destructor called." << std::endl;
}

Contact* Contact::createContact(std::string firstName,
	std::string lastName, std::string nickname, std::string secret, std::string number)
{
	return (new Contact(firstName, lastName, nickname, secret, number));
}

std::string Contact::getNumber()
{
	return (this->number);
}

std::string Contact::getFirstName()
{
	return (this->firstName);
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

std::string Contact::getNickname()
{
	return (this->nickname);
}

std::string Contact::getSecret()
{
	return (this->secret);
}
