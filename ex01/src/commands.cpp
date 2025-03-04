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
//Si alguno de los inputs tiene ' ' '\n' o '\0' borrar y volver a los comandos iniciales.
static void	putLine(contact  *contacts, std::string aContactData, int i)
{
	std::cout << "|";
	for (int j = 0; j < contacts[i].getName().size(); j++)
	{
		if (j == 10 && aContactData[j + 1])
			std::cout << "."; break ;
		std::cout << aContactData[j];
	}
	std::cout << "|";
}
//si el size > 10 hacer el bucle normal, si es < 10 hacer una resta de 10 - size y un bucle que llene de "-"
static void	putColumns(phonebook phoneB)
{
	contact 	*contacts = phoneB.getContacts();
	std::string	aContactData;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|----------||----------||----------||----------|" << std::endl;
		aContactData = "0" + i;
		putLine(contacts, aContactData, i);
		aContactData = contacts[i].getFirstName();
		putLine(contacts, aContactData, i);
		aContactData = contacts[i].getLastName();
		putLine(contacts, aContactData, i);
		aContactData = contacts[i].getNumber();
		putLine(contacts, aContactData, i);
		std::cout << "|----------||----------||----------||----------|" << std::endl;
	}
}

void	Search(phonebook phoneB)
{
	putColumns(phoneB);
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