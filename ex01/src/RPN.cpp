#include <RPN.hpp>

const char* ErrorException::what() const throw()
{
	return ("Error");
}

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

bool finalValidation(std::string input)
{
	for(size_t i = 0; i < input.size(); i++)
	{
		if (!isspace(input[i]))
			return (false);
	}
	return (true);
}

void ftRpn(char *input)
{
	std::stack<int> iStack;
	int				index;
	
	for (size_t i = 0; i < strlen(input); i++)
	{
		if (iStack.size() < 2)
		{
			if (isdigit(input[i]) && (!input[i + 1] || isspace(input[i + 1])))
			{
				index = i + 2;
				int	value = input[i] - 48;
				iStack.push(value);
				input[i] = ' ';
			}
		}
		else if (isToken(input[i]) &&(!input[i + 1] || isspace(input[i + 1])))
		{
			if (iStack.size() >= 2)
			{
				int right = iStack.top();
				iStack.pop();
				int left = iStack.top();
				iStack.pop();
				if (input[i] == '-')
					iStack.push(left - right);
				if (input[i] == '+')
					iStack.push(left + right);
				if (input[i] == '/')
				{
					if (left == 0 || right == 0)
						throw ErrorException();
					iStack.push(left / right);
				}
				if (input[i] == '*')
					iStack.push(left * right);
				input[i] = ' ';
				i = index - 1;
			}
			else
				throw ErrorException();
		}
		else if (isspace(input[i]) || isdigit(input[i]))
			continue ;
		else
			throw ErrorException();
	}
	if (iStack.size() > 1)
		throw ErrorException();
	if (!finalValidation(input))
		throw ErrorException();
	std::cout << iStack.top() << std::endl;
}
