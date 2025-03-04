#include "../include/ex01.hpp"

contact::contact()
{
	std::cout << "Contact default constructor called." << std::endl;
}

contact::contact(std::string firstName, std::string secondName, std::string number)
{
	std::cout << "Contact alternative constructor called." << std::endl;
	this->firstName = firstName;
	this->lastName = secondName;
	this->number = number;
}

contact::~contact()
{
	std::cout << "Contact default destructor called." << std::endl;
}

contact* contact::createContact(std::string firstName, std::string secondName, std::string number)
{
	return (new contact(firstName, secondName, number));
}

std::string contact::getNumber()
{
	return (this->number);
}

std::string contact::getFirstName()
{
	return (this->firstName);
}

std::string contact::getLastName()
{
	return (this->lastName);
}
