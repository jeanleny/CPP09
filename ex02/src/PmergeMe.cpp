#include <PmergeMe.hpp>


/*==================VECTOR=========================
===================================================*/
void	pushBlock(std::vector<int> &first, std::vector<int> &second, size_t blockSize, size_t indexBlock)
{
	size_t index = convertIndex(indexBlock, blockSize);
	for(size_t i = 0 ; i < blockSize; i++)
	{
		first.push_back(second[index + i]);
	}
}

void setDeque(std::vector<int> &first, std::vector<int> &second, std::vector<int> nb, size_t blockSize)
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

void	insertBlock(std::vector<int> &nb, std::vector<int> &nb2, size_t index, size_t index2, size_t blockSize)
{
	std::vector<int>::iterator it = nb.begin() + convertIndex(index, blockSize);
	std::vector<int>::iterator it2 = nb2.begin() + convertIndex(index2, blockSize);

	for (size_t i = 0;  i < blockSize; i++)
	{
		it = nb.insert(it, *it2);
		++it; 
		++it2;
	}
}

int		blockValue(std::vector<int> nb, size_t indexBlock, size_t blockSize)
{
	size_t index = convertIndex(indexBlock, blockSize);
	return(nb[index + blockSize - 1]);
}

size_t getDicho(int value, std::vector<int> nb, size_t size, size_t blockSize)
{
	int end = size - 1;
	int start = 0;
	int mid;
	while(start < end)
	{
		mid = (start + end) / 2;
		if (value == blockValue(nb, mid, blockSize))
			return (mid + 1);
		if (value > blockValue(nb, mid, blockSize))
			start = mid + 1;
		else
			end = mid - 1;
	}
	if (value > blockValue(nb, start, blockSize))
		return (start + 1);
	else
		return (start);
}

void	searchNInsert(std::vector<int> &first, std::vector<int> &second, size_t blockSize, size_t index, size_t comp)
{
	int bv =  blockValue(second, index, blockSize);
	size_t dicho = getDicho(bv, first, comp, blockSize);
	insertBlock(first, second, dicho, index, blockSize);
}

void	insert(std::vector<int> &nb, size_t blockSize)
{
	std::vector<int> first;
	std::vector<int> second;
	size_t	t_k = 1;
	size_t	oldTk = 1;
	size_t	k = 2;
	size_t	comp = 1;
	
	setDeque(first, second, nb, blockSize);

	insertBlock(first, second, 0, 0, blockSize);
	for (; oldTk < getNbBlock(second.size(), blockSize); k++)
	{
		oldTk = t_k;
		t_k = getTk(oldTk, k);
		comp = getComp(oldTk, t_k);
		if (comp > getNbBlock(first.size(), blockSize))
			comp = getNbBlock(first.size(), blockSize);
		for (size_t i = t_k; i > oldTk; i--)
		{
			if (i > getNbBlock(second.size(), blockSize))
				continue;
			searchNInsert(first, second, blockSize, i - 1, comp);
		}
	}
	nb = first;
}


void	displayVector(std::vector<int> nb)
{
	for (size_t i = 0; i < nb.size(); i++)
	{
		std::cout << nb[i] << " ";	
	} 
	std::cout << std::endl;
}

void	swapBlock(size_t blockSize, std::vector<int> &nb, size_t i1, size_t i2)
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

void	FjMerge(size_t blockSize, std::vector<int> &nb)
{
	size_t i = blockSize - 1;
	for (; i < nb.size(); i += blockSize)
	{
		if (outOfBounds(i + blockSize, nb.size()) && swapNeeded(nb[i], nb[i + blockSize]))
			swapBlock(blockSize, nb, i, i + blockSize);
		i += blockSize;
	}
}

void	FjCallBack(size_t blockSize, size_t nbSize, std::vector<int> &nb)
{
	if (blockSize > nbSize / 2)
		return;
	FjMerge(blockSize, nb);
	FjCallBack(blockSize * 2, nbSize, nb);
	insert(nb, blockSize);
}

void	PmergeMe(std::vector<int> &nb)
{
	size_t blockSize = 1;
	size_t	nbSize = nb.size();

	FjCallBack(blockSize, nbSize, nb);
}





/*====================DEQUE=========================
===================================================*/

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

void	insertBlock(std::deque<int> &nb, std::deque<int> &nb2, size_t index, size_t index2, size_t blockSize)
{
	std::deque<int>::iterator it = nb.begin() + convertIndex(index, blockSize);
	std::deque<int>::iterator it2 = nb2.begin() + convertIndex(index2, blockSize);

	for (size_t i = 0;  i < blockSize; i++)
	{
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

size_t getDicho(int value, std::deque<int> nb, size_t size, size_t blockSize)
{
	int end = size - 1;
	int start = 0;
	int mid;
	while(start < end)
	{
		mid = (start + end) / 2;
		if (value == blockValue(nb, mid, blockSize))
			return (mid + 1);
		if (value > blockValue(nb, mid, blockSize))
			start = mid + 1;
		else
			end = mid - 1;
	}
	if (value > blockValue(nb, start, blockSize))
		return (start + 1);
	else
		return (start);
}

void	searchNInsert(std::deque<int> &first, std::deque<int> &second, size_t blockSize, size_t index, size_t comp)
{
	int bv =  blockValue(second, index, blockSize);
	size_t dicho = getDicho(bv, first, comp, blockSize);
	insertBlock(first, second, dicho, index, blockSize);
}

void	insert(std::deque<int> &nb, size_t blockSize)
{
	std::deque<int> first;
	std::deque<int> second;
	size_t	t_k = 1;
	size_t	oldTk = 1;
	size_t	k = 2;
	size_t	comp = 1;
	
	setDeque(first, second, nb, blockSize);

	insertBlock(first, second, 0, 0, blockSize);
	for (; oldTk < getNbBlock(second.size(), blockSize); k++)
	{
		oldTk = t_k;
		t_k = getTk(oldTk, k);
		comp = getComp(oldTk, t_k);
		if (comp > getNbBlock(first.size(), blockSize))
			comp = getNbBlock(first.size(), blockSize);
		for (size_t i = t_k; i > oldTk; i--)
		{
			if (i > getNbBlock(second.size(), blockSize))
				continue;
			searchNInsert(first, second, blockSize, i - 1, comp);
		}
	}
	nb = first;
}


void	displayDeque(std::deque<int> nb)
{
	for (size_t i = 0; i < nb.size(); i++)
	{
		std::cout << nb[i] << " ";	
	} 
	std::cout << std::endl;
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
