#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

//NONCONTAINER
bool			swapNeeded(int nb1, int nb2);
bool			strIsDigit(std::string str);
bool			isValidInput(size_t size, char **input, std::deque<int>&nb, std::vector<int> &vnb);
size_t			convertIndex(size_t indexBlock, size_t blockSize);
size_t			getNbBlock(size_t size, size_t blockSize);
int				getExp(int nb, int exp);
size_t			getTk(size_t  oldTk, int k);
size_t			getComp(size_t oldTk, size_t t_k);
bool			swapNeeded(int nb1, int nb2);
bool			outOfBounds(size_t index, size_t bound);

//VECTOR
void			PmergeMe(std::vector<int> &nb);
void			FjMerge(size_t blockSize, std::vector<int> &nb);
void			FjCallBack(size_t blockSize, size_t nbSize, std::vector<int> &nb);
void			displayVector(std::vector<int> nb);
void			insert(std::vector<int>& nb, size_t blockSize);

//DEQUE
void			PmergeMe(std::deque<int> &nb);
void			FjMerge(size_t blockSize, std::deque<int> &nb);
void			FjCallBack(size_t blockSize, size_t nbSize, std::deque<int> &nb);
void			displayDeque(std::deque<int> nb);
void			insert(std::deque<int>& nb, size_t blockSize);

#endif
