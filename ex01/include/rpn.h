#ifndef RPN_H
# define RPN_H

#include <stack>
#include <iostream>
#include <cstdlib>
#include <string.h>

bool	isToken(char a);
bool	validTokens(std::string str);
void	ftRpn(char *input);


#endif
