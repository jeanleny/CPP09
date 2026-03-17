#include <rpn.h>

bool	isToken(char a)
{
	return (a == '+' || a == '-' || a == '/' || a == '*');
}

bool validTokens(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && !isToken(str[i]) && !isspace(str[i]))
			return (false);
	}
	return (true);
}
