#include <PmergeMe.hpp>

bool	strIsDigit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isValidInput(size_t size,char **input, std::deque<int>& nb)
{
	(void)nb;
	for (size_t i = 0; i < size; i++)
	{
		if (!strIsDigit(input[i]))
			return (false);
		nb.push_back(atoi(input[i]));
	}
	return (true);
}



int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::deque<int> nb;
		if (!isValidInput(argc - 1, argv + 1, nb))
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
		std::cout << "Before:";
		for (size_t i = 0; i < nb.size(); i++)
		{
			std::cout << nb[i] << " ";
		}
		std::cout << std::endl;
		PmergeMe(nb);
	}
}
