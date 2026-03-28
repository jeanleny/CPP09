#include <PmergeMe.hpp>

bool	swapNeeded(int nb1, int nb2)
{
	return (nb1 > nb2);	
}

bool	outOfBounds(size_t index, size_t bound)
{
	return (index < bound);
}

size_t	getComp(size_t oldTk, size_t t_k)
{
	return (oldTk + t_k - 1);
}

size_t	getTk(size_t  oldTk, int k)
{
	size_t newTk;

	newTk = getExp(2, k) - oldTk;
	return (newTk);
}

int	getExp(int nb, int exp)
{
	int res = nb;
	for (int i = 1; i < exp; i++)
		res *= nb;
	return(res);
}

bool	isValidInput(size_t size,char **input, std::deque<int>& nb, std::vector<int> &vnb)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strIsDigit(input[i]))
			return (false);
		nb.push_back(atoi(input[i]));
		vnb.push_back(atoi(input[i]));
	}
	return (true);
}

bool	strIsDigit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

size_t	getNbBlock(size_t size, size_t blockSize)
{
	return(size / blockSize);
}

size_t	convertIndex(size_t indexBlock, size_t blockSize)
{
	return (indexBlock * blockSize);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::deque<int> nb;
		std::vector<int> vnb;
		if (!isValidInput(argc - 1, argv + 1, nb, vnb))
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
		std::cout << "Before:";
		for (size_t i = 0; i < nb.size(); i++)
			std::cout << nb[i] << " ";
		std::cout << "\n\n\n" << std::endl;
		PmergeMe(nb);
		displayDeque(nb);
	}
}
