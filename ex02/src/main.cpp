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

void setDeque(std::deque<int> &first, std::deque<int> &second, std::deque<int> nb)
{
	for (size_t i = 0; i < nb.size(); i++)
	{
		if (i % 2 == 0)
			second.push_back(nb[i]);
		else
			first.push_back(nb[i]);
	}
}

int	getExp(int nb, int exp)
{
	int res = nb;
	for (int i = 1; i < exp; i++)
	{
		res *= nb;
	}
	return(res);
}

/*size_t	getTk(size_t  oldTk, int index)
{
	size_t newTk = oldTk - 1 + getExp(index, 2) - 1;
}*/

void	insert(std::deque<int> nb)
{
	std::deque<int> first;
	std::deque<int> second;
	//size_t	t_k = 0;
	
	setDeque(first, second, nb);
	displayDeque(first);
	displayDeque(second);
	std::cout << "exp : " << getExp(9, 9) << std::endl;
	/*for (size_t t_k = 0; t_k < second.size(); i++)
	{
	}*/
}

int main(int argc, char **argv)
{
	int value[] = {1, 2, 4, 5, 3, 6, 7, 9, 8, 10, 11};
	std::deque<int> val;
	for (size_t j = 0; j < 11; j++)
		val.push_back(value[j]);
	//displayDeque(val);
	insert(val);
	return (1);
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
