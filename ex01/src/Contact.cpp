#include "../include/ex01.hpp"

contact::contact()
{
	std::cout << "Contact default constructor called." << std::endl;
}

contact::contact(std::string name, int number)
{
	std::cout << "Contact alternative constructor called." << std::endl;
	this->name = name;
	this->number = number;
}

contact::~contact()
{
	std::cout << "Contact default destructor called." << std::endl;
}

int contact::getNumber()
{
	return (this->number);
}