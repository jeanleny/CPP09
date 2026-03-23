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

size_t	getNbBlock(size_t size, size_t blockSize)
{
	return(size / blockSize);
}

size_t	convertIndex(size_t indexBlock, size_t blockSize)
{
	return (indexBlock * blockSize);
}

void	pushBlock(std::deque<int> &first, std::deque<int> &second, size_t blockSize, size_t indexBlock)
{
	size_t index = convertIndex(indexBlock, blockSize);
	for(size_t i = 0 ; i < blockSize; i++)
	{
		first.push_back(second[index + i]);
	}
}

void setDeque(std::deque<int> &first, std::deque<int> &second, std::deque<int> nb, size_t blockSize)
{
	size_t i;
	for (i = 0; i < getNbBlock(nb.size(), blockSize); i++)
	{
		if (i % 2 == 0)
			pushBlock(second, nb, blockSize, i);
		else
			pushBlock(first, nb, blockSize, i);
	}
	for (i = convertIndex(i, blockSize); i < nb.size(); i++)
		first.push_back(nb[i]);
}

int	getExp(int nb, int exp)
{
	int res = nb;
	for (int i = 1; i < exp; i++)
		res *= nb;
	return(res);
}

size_t	getTk(size_t  oldTk, int k)
{
	size_t newTk;

	newTk = getExp(2, k) - oldTk;
	return (newTk);
}

size_t	getComp(size_t oldTk, size_t t_k)
{
	return (oldTk + t_k - 1);
}

void	insertBlock(std::deque<int> &nb, std::deque<int> &nb2, size_t index, size_t index2, size_t blockSize)
{
	std::deque<int>::iterator it = nb.begin() + convertIndex(index, blockSize);
	std::deque<int>::iterator it2 = nb2.begin() + convertIndex(index2, blockSize);

	for (size_t i = 0;  i < blockSize; i++)
	{
		std::cout << "insert : " << *it2 << std::endl;
		std::cout << "insert pos : " << *it << std::endl;
		it = nb.insert(it, *it2);
		++it;
		++it2;
	}
}

int		blockValue(std::deque<int> nb, size_t indexBlock, size_t blockSize)
{
	size_t index = convertIndex(indexBlock, blockSize);
	return(nb[index + blockSize - 1]);
}

void	searchNInsert(std::deque<int> &first, std::deque<int> &second, size_t blockSize, size_t index)
{
	bool inserted = false;
	for (size_t j = 0; !inserted; j++)
	{
		if (j >= getNbBlock(first.size(), blockSize))
		{
			inserted = true;
			insertBlock(first, second, j, index, blockSize);
			continue;
		}
		if (swapNeeded(blockValue(first, j, blockSize), blockValue(second, index, blockSize)))
		{
			insertBlock(first, second, j, index, blockSize);
			inserted = true;
			continue ;
		}
	}
}

void	insert(std::deque<int> nb, size_t blockSize)
{
	std::deque<int> first;
	std::deque<int> second;
	size_t	t_k = 1;
	size_t	oldTk = 1;
	size_t	k = 2;
	//size_t	comp = 1;
	
	setDeque(first, second, nb, blockSize);

	std::cout << "before : \n";
	insertBlock(first, second, 0, 0, blockSize);
	displayDeque(first);
	displayDeque(second);
	for (; oldTk < getNbBlock(second.size(), blockSize); k++)
	{
		oldTk = t_k;
		t_k = getTk(oldTk, k);
		std::cout << "t_k : " << t_k << std::endl;
	//	comp = getComp(oldTk, t_k);
		for (size_t i = t_k; i > oldTk; i--)
		{
			if (i > getNbBlock(second.size(), blockSize))
				continue;
			searchNInsert(first, second, blockSize, i - 1);
		}
		displayDeque(first);
		displayDeque(second);
		std::cout << std::endl;
	}
	std::cout << "after : \n";
}

int main(int argc, char **argv)
{
	//int value[] = {1, 2, 4, 5, 3, 6, 7, 9, 8, 10, 11};
	int value[] = {4, 5, 3, 6, 7, 9, 8, 10, 1, 2, 11};
	std::deque<int> val;
	for (size_t j = 0; j < 11; j++)
		val.push_back(value[j]);
	insert(val, 2);
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
