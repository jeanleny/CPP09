#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

/*typedef struct s_comp 
{
	int	first;
	int	second;
} t_comp;*/

bool			swapNeeded(int nb1, int nb2);
bool			strIsDigit(std::string str);
bool			isValidInput(size_t size, char **input);
void			PmergeMe(std::deque<int> nb);
void			FjCallBack(size_t blockSize, size_t nbSize, std::deque<int> nb);
void	displayDeque(std::deque<int> nb);

#endif
