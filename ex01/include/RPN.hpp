#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>
#include <string.h>

class ErrorException: public std::exception
{
	public :
		const char * what() const throw();
};

bool	isToken(char a);
bool	validTokens(std::string str);
void	ftRpn(char *input);


#endif
