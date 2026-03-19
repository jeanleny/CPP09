#include <PmergeMe.hpp>

void	displayDeque(std::deque<int> nb)
{	std::cout << "nb : ";
	for (size_t i = 0; i < nb.size(); i++)
	{
		std::cout << nb[i] << " ";	
	} 
	std::cout << std::endl;
}

/*void	swapBlock(size_t blockSize, std::deque<int> &nb, size_t index)
{
	std::deque<int> newNb;
	size_t i;

}*/

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
				//swapBlock(blockSize, nb, i);
		}
		i += blockSize;
	}
}

void	FjCallBack(size_t blockSize, size_t nbSize, std::deque<int> nb)
{
	std::cout << "block size : " << blockSize << std::endl;
	if (blockSize > nbSize / 2)
		return;
	FjMerge(blockSize, nb);
	displayDeque(nb);
	FjCallBack(blockSize * 2, nbSize, nb);
}

void	PmergeMe(std::deque<int> nb)
{
	size_t blockSize = 1;
	size_t	nbSize = nb.size();

	FjCallBack(blockSize, nbSize, nb);
}
