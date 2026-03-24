#include <PmergeMe.hpp>

void	displayDeque(std::deque<int> nb)
{	std::cout << "nb : ";
	for (size_t i = 0; i < nb.size(); i++)
	{
		std::cout << nb[i] << " ";	
	} 
	std::cout << std::endl;
}

bool	swapNeeded(int nb1, int nb2)
{
	return (nb1 > nb2);	
}

bool	outOfBounds(size_t index, size_t bound)
{
	return (index < bound);
}

void	swapBlock(size_t blockSize, std::deque<int> &nb, size_t i1, size_t i2)
{
	int	tmp;
	for(size_t i = 0; i < blockSize; i++)
	{
		tmp = nb[i1];
		nb[i1] = nb[i2];
		nb[i2] = tmp;
		i2--;
		i1--;
	}
}

void	FjMerge(size_t blockSize, std::deque<int> &nb)
{
	size_t i = blockSize - 1;
	for (; i < nb.size(); i += blockSize)
	{
		if (outOfBounds(i + blockSize, nb.size()) && swapNeeded(nb[i], nb[i + blockSize]))
			swapBlock(blockSize, nb, i, i + blockSize);
		i += blockSize;
	}
}

void	FjCallBack(size_t blockSize, size_t nbSize, std::deque<int> &nb)
{
	if (blockSize > nbSize / 2)
		return;
	FjMerge(blockSize, nb);
	FjCallBack(blockSize * 2, nbSize, nb);
	insert(nb, blockSize);
}

void	PmergeMe(std::deque<int> &nb)
{
	size_t blockSize = 1;
	size_t	nbSize = nb.size();

	FjCallBack(blockSize, nbSize, nb);
}
