#include "../include/ex01.hpp"

static void	CheckAnswer(std::string answer, phonebook phoneB)
{
	if (answer == "EXIT")
		std::exit(0);
	if (answer == "ADD")
		Add(phoneB);
	else if (answer == "SEARCH")
		Search(phoneB);
}

int	main(void)
{
	std::string	answer;
	phonebook	phoneB;

	while (1)
	{
		std::cout << "Enter command: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> answer;
		CheckAnswer(answer, phoneB);
	}
	return (0);
}
