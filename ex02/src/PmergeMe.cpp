#include <PmergeMe.hpp>

void	swapBlock(size_t blockSize, std::deque<int> &nb, size_t index)
{
	std::deque<int> newNb;
	size_t i;
	for (i = 0; i < index; i++)
		newNb.push_back(nb[i]);
	for (; index < index + blockSize; index ++)
		newNb.push_back(nb[index]);
	for (; index < nb.size(); index++)
		newNb.push_back(nb[index]);
	nb = newNb;
}

void	FjMerge(size_t blockSize, std::deque<int> &nb)
{
	size_t i = blockSize - 1;
	for (; i < nb.size(); i += blockSize)
	{
		if (i + blockSize < nb.size())
		{
//			if (nb[i] < nb[i + blockSize])
//				swapBlock(blockSize, nb, index);
//			else
				swapBlock(blockSize, nb, i);
		}
		else
			std::cout << "nb" << nb[i];
		std::cout << std::endl; 
		i += blockSize;
	}
}

void	FjCallBack(size_t blockSize, size_t nbSize, std::deque<int> nb)
{
	std::cout << "block size : " << blockSize << std::endl;
	if (blockSize > nbSize / 2)
		return;
	FjMerge(blockSize, nb);
	FjCallBack(blockSize * 2, nbSize, nb);
}

void	PmergeMe(std::deque<int> nb)
{
	size_t blockSize = 1;
	size_t	nbSize = nb.size();

	FjCallBack(blockSize, nbSize, nb);
}
