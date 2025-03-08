#include "../include/ex01.hpp"

static void	checkAnswer(std::string answer, Phonebook *phoneB)
{
	if (answer.empty())
		return ;
	if (answer == "EXIT")
		std::exit(0);
	if (answer == "ADD")
		add(phoneB);
	else if (answer == "SEARCH")
		search(phoneB);
}

int	main(void)
{
	std::string	answer;
	Phonebook	phoneB;

	while (1)
	{
		std::cout << "Enter command: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> answer;
		if (std::cin.eof())
			phoneB.~Phonebook(), std::exit(0);
		checkAnswer(answer, &phoneB);
	}
	return (0);
}
